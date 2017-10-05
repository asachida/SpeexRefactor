/**
*	Header: SpeexCommonUtilities.h
*	Description: Common utilities such as endian conversions.
*
*/
#pragma once

#include <cstdint>

class SpeexCommonUtilities
{
public:
	/**
	*	Convert 32 bit integer to Little Endian
	*/
	static int32_t LittleEndianInt32(int32_t i);

	/**
	*	Convert 16 bit integer to Little Endian
	*/
	static int16_t LittleEndianInt16(int16_t s);
};