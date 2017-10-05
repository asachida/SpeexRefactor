#include <iostream>

#include "Common/SpeexBitStream.h"
#include "Common/Definitions.h"

SpeexBitStream::SpeexBitStream():
m_rawDataPtr(nullptr), m_noOfBits(0), m_byteCursorPosition(-1), m_bitCursorPosition(-1), m_owner(0), m_overflow(0), m_bufSize(0), m_reserved1(0), m_reserved2(nullptr)
{

}

SpeexBitStream::SpeexBitStream(const SpeexBitStream& rhs)
{
	if (rhs.m_rawDataPtr)
	{
		int32_t len = strlen(rhs.m_rawDataPtr);
		m_rawDataPtr = new char[len];
		strcpy(m_rawDataPtr, rhs.m_rawDataPtr);
	}
	else
	{
		m_rawDataPtr = nullptr;
	}

	m_noOfBits = rhs.m_noOfBits;
	m_byteCursorPosition = rhs.m_byteCursorPosition;
	m_bitCursorPosition = rhs.m_bitCursorPosition;
	m_owner = rhs.m_owner;
	m_overflow = rhs.m_overflow;
	m_bufSize = rhs.m_bufSize;
	m_reserved1 = rhs.m_reserved1;

	if (rhs.m_reserved2)
	{
		int32_t len = strlen((char*)m_reserved2);
		m_reserved2 = new char[len];
		strcpy((char*)m_reserved2, (char*)rhs.m_reserved2);
	}
	else
	{
		m_reserved2 = nullptr;
	}
}

SpeexBitStream::~SpeexBitStream()
{
	if (m_owner && m_rawDataPtr)
	{
		delete[] m_rawDataPtr;
	}
}

void SpeexBitStream::Release()
{
	delete this;
}

void SpeexBitStream::Initialize()
{
	m_rawDataPtr = new char[MAX_CHARS_PER_FRAME];

	if (!m_rawDataPtr)
		return;

	m_bufSize = MAX_CHARS_PER_FRAME;

	m_owner = 1;

	ResetBuffer();
}

void SpeexBitStream::Initialize(void *buffer, int32_t bufSize)
{
	m_rawDataPtr = (char*)buffer;
	m_bufSize = bufSize;

	m_owner = 0;

	ResetBuffer();
}

void SpeexBitStream::SetBuffer(void *buffer, int32_t bufSize)
{
	m_rawDataPtr = (char*)buffer;
	m_bufSize = bufSize;

	m_owner = 0;

	m_noOfBits = bufSize << LOG2_BITS_PER_CHAR;
	m_byteCursorPosition = 0;
	m_bitCursorPosition = 0;
	m_overflow = 0;
}

void SpeexBitStream::ResetBuffer()
{
	/* We only need to clear the first byte now */
	m_rawDataPtr[0] = 0;
	m_noOfBits = 0;
	m_byteCursorPosition = 0;
	m_bitCursorPosition = 0;
	m_overflow = 0;
}

void SpeexBitStream::Rewind()
{
	m_byteCursorPosition = 0;
	m_bitCursorPosition = 0;
	m_overflow = 0;

}

void SpeexBitStream::ReadFrom(const char* bytes, int32_t length)
{
	int32_t i;
	int32_t nchars = length / BYTES_PER_CHAR;
	if (nchars > m_bufSize)
	{
		std::cout << "Packet is larger than allocated buffer";

		if (m_owner)
		{
			char *tmp = new char[nchars];

			if (tmp)
			{
				m_bufSize = nchars;
				m_rawDataPtr = tmp;
			}
			else 
			{
				nchars = m_bufSize;
				std::cout << "Could not resize input buffer: truncating input";
			}
		}
		else
		{
			std::cout << "Do not own input buffer: truncating oversize input";
			nchars = m_bufSize;
		}
	}
	
	for (i = 0; i < nchars; i++)
	{
		m_rawDataPtr[i] = HTOLS(m_rawDataPtr[i]);
	}

	m_noOfBits = nchars << LOG2_BITS_PER_CHAR;
	m_byteCursorPosition = 0;
	m_bitCursorPosition = 0;
	m_overflow = 0;
}

void SpeexBitStream::ReadWholeBytes(const char* bytes, int32_t length)
{

}

int32_t SpeexBitStream::WriteTo(char* bytes, int32_t maxLength)
{
	return 0;
}

void SpeexBitStream::WriteWholeBytes(char* bytes, int32_t maxLength)
{

}

void SpeexBitStream::Pack(int32_t data, int32_t noOfBits)
{

}

int32_t SpeexBitStream::UnPack(bool interpretSigned, int32_t noOfBits)
{
	return 0;
}

int32_t SpeexBitStream::GetNoOfBytes()
{
	// Implementation Required
	return 0;
}

int32_t SpeexBitStream::Peek()
{
	// Implementation Required
	return 0;
}

uint32_t SpeexBitStream::PeekUnsigned(int32_t noOfBits)
{
	// Implementation Required
	return 0;
}

void SpeexBitStream::Forward(int32_t n)
{

}

int32_t SpeexBitStream::RemainingBitsToRead()
{
	// Implementation Required
	return 0;
}

void SpeexBitStream::InsertTerminator()
{

}
