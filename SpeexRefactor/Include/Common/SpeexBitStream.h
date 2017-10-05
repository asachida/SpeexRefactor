#pragma once
#include "Common/ISpeexBitStream.h"
#include <memory>

class SpeexBitStream :public ISpeexBitStream
{
private:
	char*	  m_rawDataPtr;			/**< "raw" data */
	int32_t   m_noOfBits;			/**< Total number of bits stored in the stream*/
	int32_t   m_byteCursorPosition;	/**< Position of the byte "cursor" */
	int32_t   m_bitCursorPosition;	/**< Position of the bit "cursor" within the current char */
	int32_t   m_owner;				/**< Does the struct "own" the "raw" buffer (member "chars") */
	int32_t   m_overflow;			/**< Set to one if we try to read past the valid data */
	int32_t   m_bufSize;			/**< Allocated size for buffer */
	int32_t   m_reserved1;			/**< Reserved for future use */
	void	  *m_reserved2;			/**< Reserved for future use */

public:
	SpeexBitStream();
	SpeexBitStream(const SpeexBitStream& rhs);
	~SpeexBitStream();

	void Release() override;
	void Initialize() override;
	void Initialize(void *buffer, int32_t bufSize) override;
	void SetBuffer(void *buffer, int32_t bufSize) override;
	void ResetBuffer() override;
	void Rewind() override;
	void ReadFrom(const char* bytes, int32_t length) override;
	void ReadWholeBytes(const char* bytes, int32_t length) override;
	int32_t WriteTo(char* bytes, int32_t maxLength) override;
	void WriteWholeBytes(char* bytes, int32_t maxLength) override;
	void Pack(int32_t data, int32_t noOfBits) override;
	int32_t UnPack(bool interpretSigned, int32_t noOfBits) override;
	int32_t GetNoOfBytes() override;
	int32_t Peek() override;
	uint32_t PeekUnsigned(int32_t noOfBits) override;
	void Forward(int32_t n) override;
	int32_t RemainingBitsToRead() override;
	void InsertTerminator() override;
};

typedef std::unique_ptr<SpeexBitStream> SpeexBitStreamUniquePtr;