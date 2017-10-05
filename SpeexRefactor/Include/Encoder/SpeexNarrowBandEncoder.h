/**
*	Header: SpeexNarrowBandEncoder.h
*	Description: Narrow band encoder (6000Hz - 12500Hz)
*
*/
#pragma once
#include "Encoder/SpeexEncoder.h"
#include "Encoder/ISpeexEncoder.h"
#include "Common/SpeexBitStream.h"
#include "Common/SpeexHeader.h"

class SpeexNarrowBandEncoder : public ISpeexEncoder, SpeexEncoder
{
private:
	SpeexBitStreamUniquePtr m_bitStreamPtr;

	SpeexHeaderUniquePtr m_headerPtr;

public:
	SpeexNarrowBandEncoder();
	~SpeexNarrowBandEncoder();

	virtual void Release() override;

	virtual bool Initialize() override;
	virtual bool Encode(const std::string& filepath) override;

	virtual void SetFrameSize(int32_t size);
	virtual int GetFrameSize();

	virtual void SetComplexity(int32_t complexity);
	virtual int GetComplexity();

	virtual void SetSamplingRate(int32_t rate);
	virtual int GetSamplingRate();

	virtual void SetVBRMaxBitRate(int32_t maxBitRate);
	virtual int GetVBRMaxBitRate();

	virtual void SetVBREncQuality(int32_t vbrQuality);
	virtual int GetVBREncQualiy();

	virtual void SetEncQuality(int32_t quality);
	virtual int GetEncQuality();

	virtual void SetBitRate(int32_t bitRate);
	virtual int GetBitRate();

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