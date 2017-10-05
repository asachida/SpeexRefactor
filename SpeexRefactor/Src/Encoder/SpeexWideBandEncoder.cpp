#include "Encoder/SpeexWideBandEncoder.h"

SpeexWideBandEncoder::SpeexWideBandEncoder()
{

}

SpeexWideBandEncoder::~SpeexWideBandEncoder()
{

}

void SpeexWideBandEncoder::Release()
{
	delete this;
}

bool SpeexWideBandEncoder::Initialize()
{
	m_bitStreamPtr = std::unique_ptr<SpeexBitStream>(new SpeexBitStream());

	m_bitStreamPtr->Initialize();

	return true;
}

bool SpeexWideBandEncoder::Encode(const std::string& filePath)
{
	return true;
}

int32_t SpeexWideBandEncoder::EncodeFrame(float *in)
{
	return 0;
}

int32_t SpeexWideBandEncoder::EncodeFrame(short* in)
{
	return 0;
}

void SpeexWideBandEncoder::ConvertStereoFrameToMono(float *data, int32_t frame_size)
{

}

void SpeexWideBandEncoder::ConvertStereoFrameToMono(short *data, int32_t frame_size)
{

}

void SpeexWideBandEncoder::SetFrameSize(int32_t size)
{
	m_frameSize = size;
}

int32_t SpeexWideBandEncoder::GetFrameSize()
{
	return m_frameSize;
}

void SpeexWideBandEncoder::SetComplexity(int32_t complexity)
{
	m_complexity = complexity;
}

int32_t SpeexWideBandEncoder::GetComplexity()
{
	return m_complexity;
}

void SpeexWideBandEncoder::SetSamplingRate(int32_t rate)
{
	m_samplingRate = rate;
}

int32_t SpeexWideBandEncoder::GetSamplingRate()
{
	return m_samplingRate;
}

void SpeexWideBandEncoder::SetVBRMaxBitRate(int32_t maxBitRate)
{
	m_VBRMaxBitRate = maxBitRate;
}

int32_t SpeexWideBandEncoder::GetVBRMaxBitRate()
{
	return m_VBRMaxBitRate;
}

void SpeexWideBandEncoder::SetVBREncQuality(int32_t vbrQuality)
{
	m_VBREncQuality = vbrQuality;
}

int32_t SpeexWideBandEncoder::GetVBREncQualiy()
{
	return m_VBREncQuality;
}

void SpeexWideBandEncoder::SetEncQuality(int32_t quality)
{
	m_EncQuality = quality;
}

int32_t SpeexWideBandEncoder::GetEncQuality()
{
	return m_EncQuality;
}

void SpeexWideBandEncoder::SetBitRate(int32_t bitRate)
{
	m_bitRate = bitRate;
}

int32_t SpeexWideBandEncoder::GetBitRate()
{
	return m_bitRate;
}

void SpeexWideBandEncoder::EnableVBR(bool enable)
{
	m_VBREnabled = enable;
}

bool SpeexWideBandEncoder::IsVBREnabled()
{
	return m_VBREnabled;
}

void SpeexWideBandEncoder::EnableVAD(bool enable)
{
	m_VADEnabled = enable;
}

bool SpeexWideBandEncoder::IsVADEnabled()
{
	return m_VADEnabled;
}

void SpeexWideBandEncoder::EnableDTX(bool enable)
{
	m_DTXEnabled = enable;
}

bool SpeexWideBandEncoder::IsDTXEnabled()
{
	return m_DTXEnabled;
}

void SpeexWideBandEncoder::EnableABR(bool enable)
{
	m_ABREnabled = enable;
}

bool SpeexWideBandEncoder::IsABREnabled()
{
	return m_ABREnabled;
}

void SpeexWideBandEncoder::EnableHighPass(bool enable)
{
	m_highPassEnabled = enable;
}

bool SpeexWideBandEncoder::IsHighPassEnabled()
{
	return m_highPassEnabled;
}