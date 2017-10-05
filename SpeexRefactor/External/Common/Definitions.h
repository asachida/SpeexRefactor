/**
*	Header: Definitions.h
*	Description: Common pre-processor directives defined in the project.
*
*/
#pragma once
#include <cinttypes>

#define BYTES_PER_CHAR 1
#define BITS_PER_CHAR 8
#define LOG2_BITS_PER_CHAR 3
#define MAX_CHARS_PER_FRAME (2000/BYTES_PER_CHAR) /* Maximum size of the bit-stream (for fixed-size allocation) */
#define MAX_SAMPLING_RATE_ALLOWED 48000
#define MAX_FRAME_SIZE 2000
#define MAX_FRAME_BYTES 2000
#define NO_OF_STEREO_CHANNELS 2
#define SPEEX_ENC_NAME "Speex   "
#define SPEEX_VERSION "speex-1.2.0"   /**< Speex version string. */

#define SPEEX_HEADER_STRING_LENGTH 8	/** Length of the Speex header identifier */
#define SPEEX_HEADER_VERSION_LENGTH 20	/** Maximum number of characters for encoding the Speex version number in the header */

#if (BYTES_PER_CHAR == 2)
/* Swap bytes to proper endian order (could be done externally) */
#define HTOLS(A) ((((A) >> 8)&0xff)|(((A) & 0xff)<<8))
#else
#define HTOLS(A) (A)
#endif