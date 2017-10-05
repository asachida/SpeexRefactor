
#pragma once
#include "Common/Definitions.h"
#include "Common/SpeexEnums.h"
#include <memory>

class SpeexHeader 
{
private:
	char m_speexEncName[SPEEX_HEADER_STRING_LENGTH];	/**< Identifies a Speex bit-stream, always set to "Speex   " */
	char m_speexVersion[SPEEX_HEADER_VERSION_LENGTH];	/**< Speex version */
	int32_t m_versionId;									/**< Version for Speex (for checking compatibility) */
	int32_t m_headerSize;									/**< Total size of the header ( sizeof(SpeexHeader) ) */
	int32_t m_rate;											/**< Sampling rate used */
	int32_t m_mode;											/**< Mode used (0 for narrowband, 1 for wideband) */
	int32_t m_bitStreamVersion;								/**< Version ID of the bit-stream */
	int32_t m_noOfChannelsEncoded;							/**< Number of channels encoded */
	int32_t m_bitRate;										/**< Bit-rate used */
	int32_t m_frameSize;									/**< Size of frames */
	int32_t m_vbr;											/**< 1 for a VBR encoding, 0 otherwise */
	int32_t m_framesPerPacket;								/**< Number of frames stored per Ogg packet */
	int32_t m_extraHeaders;									/**< Number of additional headers after the comments */
	int32_t m_reserved1;									/**< Reserved for future use, must be zero */
	int32_t m_reserved2;									/**< Reserved for future use, must be zero */

public:
	/**
	* Initializes a SpeexHeader using basic information 
	*/
	void Initialize(int32_t rate, int32_t noOfChannels, SpeexEncoderMode encModeType);


};

typedef std::unique_ptr<SpeexHeader> SpeexHeaderUniquePtr;