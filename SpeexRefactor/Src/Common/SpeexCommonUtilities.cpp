#include "Common/SpeexCommonUtilities.h"

int32_t SpeexCommonUtilities::LittleEndianInt32(int32_t i)
{

#if !defined(__LITTLE_ENDIAN__) && ( defined(WORDS_BIGENDIAN) || defined(__BIG_ENDIAN__) )
	int32_t ui, ret;
	ui = i;
	ret = ui >> 24;
	ret |= (ui >> 8) & 0x0000ff00;
	ret |= (ui << 8) & 0x00ff0000;
	ret |= (ui << 24);
	return ret;
#else
	return i;
#endif
}

int16_t SpeexCommonUtilities::LittleEndianInt16(int16_t s)
{
#if !defined(__LITTLE_ENDIAN__) && ( defined(WORDS_BIGENDIAN) || defined(__BIG_ENDIAN__) )
	return ((int16_t) (s) << 8) | ((int16_t) (s) >> 8))
#else
	return s;
#endif
}