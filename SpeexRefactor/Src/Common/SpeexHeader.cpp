#include "Common/SpeexHeader.h"
#include "Common/SpeexEnums.h"
#include "Common/Definitions.h"

#include <string>

void SpeexHeader::Initialize(int32_t rate, int32_t noOfChannels, SpeexEncoderMode encModeType)

{
	std::string encName(SPEEX_ENC_NAME);
	std::string version(SPEEX_VERSION);

	strcpy(m_speexEncName, encName.c_str());
	strcpy(m_speexVersion, version.c_str());

	m_versionId = 1;

	m_mode = (int)encModeType;

	m_bitRate = -1;

	m_vbr = 0;
	m_framesPerPacket = 0;
	m_extraHeaders = 0;
	m_reserved1 = 0;
	m_reserved2 = 0;

	m_rate = rate;
	m_noOfChannelsEncoded = noOfChannels;
}