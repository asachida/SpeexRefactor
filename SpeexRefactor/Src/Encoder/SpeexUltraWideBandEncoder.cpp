#include "Encoder/SpeexUltraWideBandEncoder.h"

SpeexUltraWideBandEncoder::SpeexUltraWideBandEncoder()
{

}

SpeexUltraWideBandEncoder::~SpeexUltraWideBandEncoder()
{

}

void SpeexUltraWideBandEncoder::Release()
{
	delete this;
}

bool SpeexUltraWideBandEncoder::Initialize()
{
	m_bitStreamPtr = std::unique_ptr<SpeexBitStream>(new SpeexBitStream());

	m_bitStreamPtr->Initialize();

	return true;
}

bool SpeexUltraWideBandEncoder::Encode(const std::string& filePath)
{
	return true;
}

int32_t SpeexUltraWideBandEncoder::EncodeFrame(float *in)
{

	return 0;
}

int32_t SpeexUltraWideBandEncoder::EncodeFrame(short* in)
{
	return 0;
}

void SpeexUltraWideBandEncoder::ConvertStereoFrameToMono(float *data, int32_t frame_size)
{

}

void SpeexUltraWideBandEncoder::ConvertStereoFrameToMono(short *data, int32_t frame_size)
{

}

void SpeexUltraWideBandEncoder::SetFrameSize(int32_t size)
{
	m_frameSize = size;
}

int32_t SpeexUltraWideBandEncoder::GetFrameSize()
{
	return m_frameSize;
}

void SpeexUltraWideBandEncoder::SetComplexity(int32_t complexity)
{
	m_complexity = complexity;
}

int32_t SpeexUltraWideBandEncoder::GetComplexity()
{
	return m_complexity;
}

void SpeexUltraWideBandEncoder::SetSamplingRate(int32_t rate)
{
	m_samplingRate = rate;
}

int32_t SpeexUltraWideBandEncoder::GetSamplingRate()
{
	return m_samplingRate;
}

void SpeexUltraWideBandEncoder::SetVBRMaxBitRate(int32_t maxBitRate)
{
	m_VBRMaxBitRate = maxBitRate;
}

int32_t SpeexUltraWideBandEncoder::GetVBRMaxBitRate()
{
	return m_VBRMaxBitRate;
}

void SpeexUltraWideBandEncoder::SetVBREncQuality(int32_t vbrQuality)
{
	m_VBREncQuality = vbrQuality;
}

int32_t SpeexUltraWideBandEncoder::GetVBREncQualiy()
{
	return m_VBREncQuality;
}

void SpeexUltraWideBandEncoder::SetEncQuality(int32_t quality)
{
	m_EncQuality = quality;
}

int32_t SpeexUltraWideBandEncoder::GetEncQuality()
{
	return m_EncQuality;
}

void SpeexUltraWideBandEncoder::SetBitRate(int32_t bitRate)
{
	m_bitRate = bitRate;
}

int32_t SpeexUltraWideBandEncoder::GetBitRate()
{
	return m_bitRate;
}

void SpeexUltraWideBandEncoder::EnableVBR(bool enable)
{
	m_VBREnabled = enable;
}

bool SpeexUltraWideBandEncoder::IsVBREnabled()
{
	return m_VBREnabled;
}

void SpeexUltraWideBandEncoder::EnableVAD(bool enable)
{
	m_VADEnabled = enable;
}

bool SpeexUltraWideBandEncoder::IsVADEnabled()
{
	return m_VADEnabled;
}

void SpeexUltraWideBandEncoder::EnableDTX(bool enable)
{
	m_DTXEnabled = enable;
}

bool SpeexUltraWideBandEncoder::IsDTXEnabled()
{
	return m_DTXEnabled;
}

void SpeexUltraWideBandEncoder::EnableABR(bool enable)
{
	m_ABREnabled = enable;
}

bool SpeexUltraWideBandEncoder::IsABREnabled()
{
	return m_ABREnabled;
}

void SpeexUltraWideBandEncoder::EnableHighPass(bool enable)
{
	m_highPassEnabled = enable;
}

bool SpeexUltraWideBandEncoder::IsHighPassEnabled()
{
	return m_highPassEnabled;
}