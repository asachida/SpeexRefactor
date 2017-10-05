#ifdef _WINDOWS
#include <windows.h>
#endif

#include "SpeexRefactorAPI.h"
#include "Encoder/SpeexNarrowBandEncoder.h"
#include "Encoder/SpeexWideBandEncoder.h"
#include "Encoder/SpeexUltraWideBandEncoder.h"
#include "Common/SpeexBitStream.h"
#include "Common/SpeexEnums.h"

ISpeexEncoder* GetEncoder(SpeexEncoderMode encType)
{
	switch(encType)
	{
	case SpeexEncoderMode::SPEEX_ENC_NARROW_BAND:
		return dynamic_cast<ISpeexEncoder*> (new SpeexNarrowBandEncoder());
	case SpeexEncoderMode::SPEEX_ENC_WIDE_BAND:
		return dynamic_cast<ISpeexEncoder*> (new SpeexWideBandEncoder());
	case SpeexEncoderMode::SPEEX_ENC_ULTRA_WIDE_BAND:
		return dynamic_cast<ISpeexEncoder*> (new SpeexUltraWideBandEncoder());
	default:
		return NULL;
	}
}

ISpeexBitStream* GetBitStreamData()
{
	return new SpeexBitStream();
}

//	ISpeexDecoder* GetDecoder();
//	{
//		return new SpeexDecoder();
//	}

#ifdef _WINDOWS
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

#endif