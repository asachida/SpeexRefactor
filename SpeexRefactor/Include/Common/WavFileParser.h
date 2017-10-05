#pragma once

#include <fstream>
#include <cstdint>
#include "Common/IFileParser.h"

class WavFileParser: public IFileParser
{
private:
	std::ifstream file;

public:
	WavFileParser();
	
	~WavFileParser();

	void Open(const std::string& absoluteFileName) override;

	void Close() override;

	int32_t ReadHeader(int32_t& rate, int32_t& channels, int32_t& format, int32_t& size) override;

	void WriteHeader(int32_t rate, int32_t channels, int32_t format, int32_t size) override;
};