#pragma once
#include "include/laboratory 1/IPrinter.hpp"
#include <string_view>

class DocumentManager
{
public:
	DocumentManager() = default;
	~DocumentManager() = default;
	void process_print_job(IPrinter& printer, std::string_view document);
};