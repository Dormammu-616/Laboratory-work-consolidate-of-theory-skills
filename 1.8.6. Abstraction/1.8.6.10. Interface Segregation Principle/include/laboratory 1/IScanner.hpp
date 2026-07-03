#pragma once
#include <string>

class IScanner
{
public:
	virtual ~IScanner() = default;
	virtual std::string scan_document() const = 0;
};