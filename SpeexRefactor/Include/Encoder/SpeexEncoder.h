/**
*	Header: SpeexEncoder.h
*	Description: Base class for differnt encoder mode sub classes
*
*/
#pragma once
#include "Common/Definitions.h"

class SpeexEncoder
{
protected:
	int m_frameSize;
	int m_complexity;
	int m_samplingRate;
	int m_VBRMaxBitRate;
	int m_VBREncQuality;
	int m_EncQuality;
	int m_bitRate;
	bool m_VBREnabled;
	bool m_VADEnabled;
	bool m_DTXEnabled;
	bool m_ABREnabled;
	bool m_highPassEnabled;

	short m_input[MAX_FRAME_SIZE];

	char m_cbits[MAX_FRAME_BYTES];

	/** Encode one frame of speech pointed to by "in". 
		The encoded bit-stream is saved in "bits".
	@param in Frame that will be encoded with a +-2^15 range. This data MAY be
	overwritten by the encoder and should be considered uninitialised
	after the call.
	@param bits Bit-stream where the data will be written
	@return 0 if frame needs not be transmitted (DTX only), 1 otherwise
	*/
	virtual int EncodeFrame(float *in) = 0;

	/** Uses an existing encoder state to encode one frame of speech pointed to by
	"in". The encoded bit-stream is saved in "bits".
	@param state Encoder state
	@param in Frame that will be encoded with a +-2^15 range
	@param bits Bit-stream where the data will be written
	@return 0 if frame needs not be transmitted (DTX only), 1 otherwise
	*/
	virtual int EncodeFrame(short *in) = 0;
	
	/** Transforms a stereo frame into a mono frame and stores intensity stereo info in 'bits' */
	virtual void ConvertStereoFrameToMono(float *data, int frame_size) = 0;

	/** Transforms a stereo frame into a mono frame and stores intensity stereo info in 'bits' */
	virtual void ConvertStereoFrameToMono(short *data, int frame_size) = 0;

};