#include "Encoder/SpeexNarrowBandEncoder.h"
#include "Common/Definitions.h"
#include "Common/Errors.h"

SpeexNarrowBandEncoder::SpeexNarrowBandEncoder()
{

}

SpeexNarrowBandEncoder::~SpeexNarrowBandEncoder()
{

}

void SpeexNarrowBandEncoder::Release()
{
	delete this;
}

bool SpeexNarrowBandEncoder::Initialize()
{
	m_bitStreamPtr = std::unique_ptr<SpeexBitStream>(new SpeexBitStream());
	
	m_headerPtr = std::unique_ptr<SpeexHeader>(new SpeexHeader());

	return true;
}

bool SpeexNarrowBandEncoder::Encode(const std::string& filePath)
{
	// Read input wav file
	// Get bit rate, no of channels, 
	int samplingRate = 0;
	int noOfChannels = 1;

	SetSamplingRate(samplingRate);

	// Initialize Speex Header object with all relevant information
	m_headerPtr->Initialize(samplingRate, noOfChannels, SpeexEncoderMode::SPEEX_ENC_NARROW_BAND);

	// Initialize Speex bit stream
	m_bitStreamPtr->Initialize();

	// Read samples from the wav input file 
	// Get the number of samples, frame size, number of channels, input data from the frame
	int frameSize = 1;

	SetFrameSize(frameSize);
	
//	while (!EndOfStream)
	{
		if (noOfChannels == NO_OF_STEREO_CHANNELS)
		{
			ConvertStereoFrameToMono( m_input, m_frameSize );
		}

		int encoded = EncodeFrame(m_input);

		if (encoded)
		{
			// Increment number of encoded frames

			// Read the next frame from wav file.

			m_bitStreamPtr->InsertTerminator();

			m_bitStreamPtr->WriteTo( m_cbits, MAX_FRAME_BYTES );

			m_bitStreamPtr->ResetBuffer();
		}
	}

	return true;
}

int SpeexNarrowBandEncoder::EncodeFrame(float *in)
{
	return 0;
}

int SpeexNarrowBandEncoder::EncodeFrame(short* in)
{
	return 0;
}

void SpeexNarrowBandEncoder::ConvertStereoFrameToMono(float *data, int32_t frame_size)
{

}

void SpeexNarrowBandEncoder::ConvertStereoFrameToMono(short *data, int32_t frame_size)
{

}

void SpeexNarrowBandEncoder::SetFrameSize(int32_t size)
{
	m_frameSize = size;
}

int SpeexNarrowBandEncoder::GetFrameSize()
{
	return m_frameSize;
}

void SpeexNarrowBandEncoder::SetComplexity(int32_t complexity)
{
	m_complexity = complexity;
}

int SpeexNarrowBandEncoder::GetComplexity()
{
	return m_complexity;
}

void SpeexNarrowBandEncoder::SetSamplingRate(int32_t rate)
{
	m_samplingRate = rate;

	if (rate > MAX_SAMPLING_RATE_ALLOWED)
	{
		//LOG(stderr, "Error: sampling rate too high: %d Hz, try down-sampling\n", rate);
		throw(ErrFatal,"Error: sampling rate too high: %d Hz, try down-sampling");
	}	
}

int32_t SpeexNarrowBandEncoder::GetSamplingRate()
{
	return m_samplingRate;
}

void SpeexNarrowBandEncoder::SetVBRMaxBitRate(int32_t maxBitRate)
{
	m_VBRMaxBitRate = maxBitRate;
}

int32_t SpeexNarrowBandEncoder::GetVBRMaxBitRate()
{
	return m_VBRMaxBitRate;
}

void SpeexNarrowBandEncoder::SetVBREncQuality(int32_t vbrQuality)
{
	m_VBREncQuality = vbrQuality;
}

int32_t SpeexNarrowBandEncoder::GetVBREncQualiy()
{
	return m_VBREncQuality;
}

void SpeexNarrowBandEncoder::SetEncQuality(int32_t quality)
{
	m_EncQuality = quality;
}

int32_t SpeexNarrowBandEncoder::GetEncQuality()
{
	return m_EncQuality;
}

void SpeexNarrowBandEncoder::SetBitRate(int32_t bitRate)
{
	m_bitRate = bitRate;
}

int32_t SpeexNarrowBandEncoder::GetBitRate()
{
	return m_bitRate;
}

void SpeexNarrowBandEncoder::EnableVBR(bool enable)
{
	m_VBREnabled = enable;
}

bool SpeexNarrowBandEncoder::IsVBREnabled()
{
	return m_VBREnabled;
}

void SpeexNarrowBandEncoder::EnableVAD(bool enable)
{
	m_VADEnabled = enable;
}

bool SpeexNarrowBandEncoder::IsVADEnabled()
{
	return m_VADEnabled;
}

void SpeexNarrowBandEncoder::EnableDTX(bool enable)
{
	m_DTXEnabled = enable;
}

bool SpeexNarrowBandEncoder::IsDTXEnabled()
{
	return m_DTXEnabled;
}

void SpeexNarrowBandEncoder::EnableABR(bool enable)
{
	m_ABREnabled = enable;
}

bool SpeexNarrowBandEncoder::IsABREnabled()
{
	return m_ABREnabled;
}

void SpeexNarrowBandEncoder::EnableHighPass(bool enable)
{
	m_highPassEnabled = enable;
}

bool SpeexNarrowBandEncoder::IsHighPassEnabled()
{
	return m_highPassEnabled;
}
