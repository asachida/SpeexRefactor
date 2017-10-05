/**
*	Header: IFileParser.h
*	Description: Interface for audio file parser and to read/write header information.
*
*/
#pragma once
#include <string>
#include <cstdint>

class IFileParser
{
public:
	/**
	*	Opens a file handle for the absoluteFileName
	*/
	virtual void Open( const std::string& absoluteFileName ) = 0;

	/**
	*	Close file handle for the opened file.
	*/
	virtual void Close() = 0;

	/**
	*	Read and dprocess the header information of the respective audio format
	*/
	virtual	int32_t ReadHeader(int32_t& rate, int32_t& channels, int32_t& format, int32_t& size) = 0;

	/**
	*	Write the information such a rate, number of channels, enoding format and size 
	*	information to the header of the respective audio format.
	*/
	virtual void WriteHeader(int32_t rate, int32_t channels, int32_t format, int32_t size) = 0;
};