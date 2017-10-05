/**
*	Header: ISpeexRefactorAPI.h
*	Description: Main Interface for DLL Export functions to be used by external clients.
*
*/
#if !defined(_SPEEX_REFACTOR_API_)
#define _SPEEX_REFACTOR_API_

#ifdef _WINDOWS
#ifndef DLLEXPORT
#define DLLEXPORT __declspec( dllexport )
#endif
#else
#define DLLEXPORT
#endif

#include "Common/SpeexEnums.h"
#include "Common/ISpeexBitStream.h"
#include "Encoder/ISpeexEncoder.h"

#ifdef __cplusplus
extern "C"
{
#endif
	
	/**
	*	GetEncoder gets a pointer to the requested type of encoder interface.
	*	Currently, the following types are supported:
	*	SPEEX_ENC_NARROW_BAND, SPEEX_ENC_WIDE_BAND, SPEEX_ENC_ULTRA_WIDE_BAND
	*/
	DLLEXPORT ISpeexEncoder* GetEncoder(SpeexEncoderMode encType);

	/**
	*	GetBitStreamData gets a pointer to the SpeexBitStream interface pointer.
	*/
	DLLEXPORT ISpeexBitStream* GetBitStreamData();

//	/**
//	*	GetDecoder gets a pointer to the requested type of decoder interface.
//	*/
//	DLLEXPORT ISpeexDecoder* GetDecoder();

#ifdef __cplusplus
}
#endif

#endif // _SPEEX_REFACTOR_API_