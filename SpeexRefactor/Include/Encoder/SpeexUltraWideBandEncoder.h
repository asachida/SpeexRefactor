/**
*	Header: SpeexUltraWideBandEncoder.h
*	Description: Ultra Wide Band Encoder (25000Hz - 48000Hz)
*
*/
#pragma once

#include "Encoder/ISpeexEncoder.h"
#include "Encoder/SpeexEncoder.h"
#include "Common/SpeexBitStream.h"

class SpeexUltraWideBandEncoder : public ISpeexEncoder, SpeexEncoder
{
private:
	SpeexBitStreamUniquePtr m_bitStreamPtr;

public:
	SpeexUltraWideBandEncoder();
	~SpeexUltraWideBandEncoder();

	virtual void Release() override;
	virtual bool Initialize() override;
	virtual bool Encode(const std::string& filepath) override;

	virtual void SetFrameSize(int32_t size);
	virtual int32_t GetFrameSize();

	virtual void SetComplexity(int32_t complexity);
	virtual int32_t GetComplexity();

	virtual void SetSamplingRate(int32_t rate);
	virtual int32_t GetSamplingRate();

	virtual void SetVBRMaxBitRate(int32_t maxBitRate);
	virtual int32_t GetVBRMaxBitRate();

	virtual void SetVBREncQuality(int32_t vbrQuality);
	virtual int32_t GetVBREncQualiy();

	virtual void SetEncQuality(int32_t quality);
	virtual int32_t GetEncQuality();

	virtual void SetBitRate(int32_t bitRate);
	virtual int32_t GetBitRate();

	virtual void EnableVBR(bool enable);
	virtual bool IsVBREnabled();

	virtual void EnableVAD(bool enable);
	virtual bool IsVADEnabled();

	virtual void EnableDTX(bool enable);
	virtual bool IsDTXEnabled();

	virtual void EnableABR(bool enable);
	virtual bool IsABREnabled();

	virtual void EnableHighPass(bool enable);
	virtual bool IsHighPassEnabled();

	virtual int EncodeFrame(float *in);
	virtual int EncodeFrame(short* in);

	virtual void ConvertStereoFrameToMono(float *data, int32_t frame_size);
	virtual void ConvertStereoFrameToMono(short *data, int32_t frame_size);

};