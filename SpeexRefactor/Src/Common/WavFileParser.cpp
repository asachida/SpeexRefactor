#include "Common/WavFileParser.h"
#include "Common/Errors.h"
#include "Common/SpeexCommonUtilities.h"
#include "Common/Definitions.h"

void WavFileParser::Open(const std::string& absoluteFileName)
{
	file.open(absoluteFileName, std::ios::in | std::ios::out | std::ios::binary);
	
	if (!file.is_open())
	{
		throw(ErrFileCannotBeOpened, "File cannot be opened");
	}
}

void WavFileParser::Close()
{
	if (file.is_open())
	{
		file.close();
	}
}

int32_t WavFileParser::ReadHeader(int32_t& rate, int32_t& channels, int32_t& format, int32_t& size)
{
	char firstBytes[12];
	char ch[5];
	int32_t itmp;
	int16_t stmp;

	int32_t bpersec;
	int16_t balign;

	int32_t skipBytes;
	//int32_t i;

	ch[4] = 0;

	if (file.is_open())
	{
		if (file.read( firstBytes, 12 ))
		{
			if (strncmp(firstBytes, "RIFF", 4) == 0 || strncmp(firstBytes, "riff", 4) == 0)
			{
				file.read(ch, 4);

				while (strcmp(ch, "fmt ") != 0)
				{
					file.read((char*)&itmp, sizeof(itmp));

					itmp = SpeexCommonUtilities::LittleEndianInt32(itmp);

					file.seekg(std::ios_base::cur);

					file.read(ch, 4);

					if (file.eof())
					{
						// LOG("Corrupted WAV File");
						return -1;
					}
				}

				file.read((char*)&itmp, sizeof(itmp));

				itmp = SpeexCommonUtilities::LittleEndianInt32(itmp);
				skipBytes = itmp - 16;

				file.read((char*)&stmp, sizeof(stmp));
				stmp = SpeexCommonUtilities::LittleEndianInt16(stmp);

				channels = stmp;

				if (stmp > NO_OF_STEREO_CHANNELS)
				{
					// LOG("Only Mono and intensity stereo supported");
					return -1;
				}

				file.read((char*)&itmp, sizeof(itmp));
				itmp = SpeexCommonUtilities::LittleEndianInt32(itmp);
				rate = itmp;

				if (rate != 8000 && rate != 16000 && 
					rate != 11025 && rate != 22050 && 
					rate != 32000 && rate != 44100 && 
					rate != 48000)
				{
					// LOG("Only 8 kHz (narrowband) and 16 kHz (wideband) supported 
					//	(plus 11.025 kHz and 22.05 kHz, but your mileage may vary)\n");
					return -1;
				}

				file.read((char*)&itmp, sizeof(itmp));
				bpersec = SpeexCommonUtilities::LittleEndianInt32(itmp);

				file.read((char*)&stmp, sizeof(stmp));
				balign = SpeexCommonUtilities::LittleEndianInt16(stmp);
				
				file.read((char*)&stmp, sizeof(stmp));
				stmp = SpeexCommonUtilities::LittleEndianInt16(stmp);
				if (stmp != 8 || stmp != 16)
				{
					// LOG("Corrupted header: ByteRate mismatch\n");
					return -1;
				}
				format = stmp;

				if (bpersec != (rate*channels*format / 8) )
				{
					// LOG("Corrupted header: ByteRate mismatch\n");
					return -1;
				}

				if (balign != (channels*format / 8))
				{
					// LOG("Corrupted header: BlockAlign mismatch\n");
					return -1;
				}

				if (skipBytes > 0)
				{
					file.seekg(std::ios::ios_base::cur + skipBytes);
				}

				file.read(ch, 4);

				while (strcmp(ch, "data") != 0)
				{
					file.read((char*)&itmp, sizeof(itmp));
					itmp = SpeexCommonUtilities::LittleEndianInt32(itmp);

					file.seekg(std::ios::ios_base::cur + itmp);

					file.read(ch, 4);

					if (file.eof())
					{
						// LOG("Corrupted Wav file\n");
						return -1;
					}
				}

				file.read((char*)&itmp, sizeof(itmp));
				itmp = SpeexCommonUtilities::LittleEndianInt32(itmp);

				size = itmp;
				return 1;
			}
			else
			{
				throw(ErrFatal, "File not supported");
			}
		}
		else
		{
			throw(ErrFatal, "File is corrupted");
		}
	}
	else
	{
		throw(ErrFileCannotBeOpened, "File cannot be opened");
	}
}

void WavFileParser::WriteHeader(int32_t rate, int32_t channels, int32_t format, int32_t size)
{

}
