/**
*	Header: ISpeexBitStream.h
*	Description: Interface for the binary audio bit stream during both encoding and decoding of audio
*
*/
#pragma once
#include <cstdint>
#include "Common/IResource.h"

class ISpeexBitStream : public IResource
{
public:
	/**
	*	@brief Initializes and allocates resources for SpeexBitStream
	*
	**/
	virtual void Initialize() = 0;

	/**
	*	@brief Initializes SpeexBits using a pre-allocated buffer
	*	@param buffer - Pre-allocated buffer
	*	@param bufSize - Size of the buffer
	**/
	virtual void Initialize(void *buffer, int32_t bufSize) = 0;

	/**
	*	@brief Sets the bits in a SpeexBitStream to use data from an existing
	*	buffer (for decoding without copying data)
	*	@param buffer - shallow copied buffer
	*	@param bufSize - Size of the buffer
	**/
	virtual void SetBuffer(void *buffer, int32_t bufSize) = 0;

	/**
	*	@brief Resets bits to initial value (just after 
	*	initialization, erasing content)
	*
	**/
	virtual void ResetBuffer() = 0;

	/**
	*	@brief Rewind the bit-stream to the beginning (ready for read) 
	*	without erasing the content
	*
	**/
	virtual void Rewind() = 0;

	/**
	*	@brief Initializes the bit-stream from the data in an area of memory
	*	@param bytes - Pointer to the data in the memory
	*	@param length - Length of data to read
	*
	**/
	virtual void ReadFrom(const char* bytes, int32_t length) = 0;

	/**
	*	@brief Append bytes to the bit-stream
	*	@param bytes pointer to the bytes what will be appended
	*	@param len Number of bytes to append
	*
	**/
	virtual void ReadWholeBytes(const char* bytes, int32_t length) = 0;

	/** 
	*	@brief Write the content of a bit-stream to an area of memory
	*	@param bytes Memory location where to write the bits
	*	@param max_len Maximum number of bytes to write (i.e. size of the "bytes" buffer)
	*	@return Number of bytes written to the "bytes" buffer
	*/	
	virtual int32_t WriteTo(char* bytes, int32_t maxLength) = 0;

	/**
	*	@brief writes only the complete bytes in the stream. Also removes the written bytes from the stream
	*	@param bytes - Pointer to the data to be written
	*	@param maxLength - maximum length to be written
	*/
	virtual void WriteWholeBytes(char* bytes, int32_t maxLength) = 0;

	/**
	*	@brief Append bits to the bit-stream
	*	@param data - Value to append as integer
	*	@param noOfBits - Number of bits to consider in "data"
	*/
	virtual void Pack(int32_t data, int32_t noOfBits) = 0;

	/** 
	*	@brief Unpack next few bits
	*	@param interpretSigned  - If true, interpret the next noOfBits in the
	*								bit-stream as a signed integer else unsigned.
	*	@param noOfBits Number of bits to interpret
	*	@return A signed integer represented by the bits read
	*/
	virtual int32_t UnPack(bool interpretSigned, int32_t noOfBits) = 0;

	/** 
	*	@brief Returns the number of bytes in the bit-stream, including the last one even if it is not "full"
	*	@return Number of bytes in the stream
	*/
	virtual	int32_t GetNoOfBytes() = 0;

	/** 
	*	@brief Get the value of the next bit in the stream, without modifying the
	*			"cursor" position.
	*	@return Value of the bit peeked (one bit only)
	*/	
	virtual int32_t Peek() = 0;

	/** 
	*	@brief Same as UnPack for unsigned, but without modifying the cursor position
	*	@param noOfBits Number of bits to look for
	*	@return Value of the bits peeked, interpreted as unsigned
	*/
	virtual uint32_t PeekUnsigned(int32_t noOfBits) = 0;

	/** 
	*	@brief Advances the position of the "bit cursor" in the stream
	*	@param n Number of bits to advance
	*/
	virtual void Forward(int32_t n) = 0;

	/** 
	*	@brief Returns the number of bits remaining to be read in a stream
	*	@return Number of bits that can still be read from the stream
	*/	
	virtual int32_t RemainingBitsToRead() = 0;

	/** 
	*	@brief Insert a terminator so that the data can be sent as a packet 
	*	while auto-detecting the number of frames in each packet.
	*/
	virtual void InsertTerminator() = 0;
};