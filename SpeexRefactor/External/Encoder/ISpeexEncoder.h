/**
*	Header: ISpeexEncoder.h
*	Description: Interface for the main encoder functionalities.
*
*/
#pragma once
#include <string>

#include "Common/IResource.h"

class ISpeexEncoder : public IResource
{
public:
	/**
	* @brief Initialize the corresponding SpeexEncoder
	* @return bool True if successful
	**/
	virtual bool Initialize() = 0;

	/**
	* @brief Encode the input file.
	* @param filePath - absolute file path of the file that needs to be encoded.
	* @return bool - True if Encoding is successful.
	**/
	virtual bool Encode(const std::string& filepath) = 0;
	
	/**
	* @brief Number of frames to be encoded
	*
	**/
	virtual void SetFrameSize(int size) = 0;

	/**
	* @brief Number of frames to be encoded
	* @return Number of frames in the file to be encoded
	**/
	virtual int GetFrameSize() = 0;

	/**
	* @brief Complexity of encoder (0 - 16)
	*
	**/
	virtual void SetComplexity(int complexity) = 0;

	/**
	* @brief Complexity of encoder (0-16)
	* @return int Complexity value
	**/
	virtual int GetComplexity() = 0;
	
	/**
	* @brief Number of samples per second.
	*	Set Sampling rate used in bit rate computation
	**/
	virtual void SetSamplingRate(int rate) = 0;

	/**
	* @brief Number of samples per second.
	* @return Get number of samples per second
	**/
	virtual int GetSamplingRate() = 0;

	/**
	* @brief Maximum value of Variable Bit Rate
	*
	**/
	virtual void SetVBRMaxBitRate(int maxBitRate) = 0;

	/**
	* @brief Maximum value of Variable Bit Rate
	* @return Max value of variable bit rate.
	**/
	virtual int GetVBRMaxBitRate() = 0;

	/**
	* @brief Variable bit rate encoding quality
	*
	**/
	virtual void SetVBREncQuality(int vbrQuality) = 0;

	/**
	* @brief Variable bit rate encoding quality
	* @return int variable bit rate encoding quality
	*
	**/
	virtual int GetVBREncQualiy() = 0;

	/**
	* @brief Set Encoder Quality
	*
	**/
	virtual void SetEncQuality(int quality) = 0;

	/**
	* @brief Get Encoder Quality
	* @return int Encoder quality
	**/
	virtual int GetEncQuality() = 0;

	/**
	* @brief Bits per second
	* 
	**/
	virtual void SetBitRate(int bitRate) = 0;

	/**
	* @brief Get Bit rate (bits per second)
	* @return int bits per second
	**/
	virtual int GetBitRate() = 0;

	/**
	* @brief Enable Variable Bit Rate Encoding
	*
	**/
	virtual void EnableVBR(bool enable) = 0;

	/**
	* @return bool TRUE If variable Bit Rate 
	* Encoding is enabled
	*
	**/
	virtual bool IsVBREnabled() = 0;

	/**
	* Enable Voice Activity Detection
	*
	**/
	virtual void EnableVAD(bool enable) = 0;

	/**
	* @retrun bool TRUE if Voice Activity Detection is enabled.
	*
	**/
	virtual bool IsVADEnabled() = 0;
	
	/**
	* @brief Enable Discontinous Transmission
	*
	**/
	virtual void EnableDTX(bool enable) = 0;

	/**
	* @return TRUE if discontinous transmission is enabled.
	*
	**/
	virtual bool IsDTXEnabled() = 0;

	/**
	* @brief Enable Adaptive Bit Rate Encoding
	*
	**/
	virtual void EnableABR(bool enable) = 0;

	/**
	* @return TRUE If Adaptive bit rate encoding is enabled.
	*
	**/
	virtual bool IsABREnabled() = 0;

	/**
	* @brief Enable High Pass Filter
	*
	**/
	virtual void EnableHighPass(bool enable) = 0;

	/**
	* @return TRUE If High Pass Filter is enabled
	*
	**/
	virtual bool IsHighPassEnabled() = 0;
};