#pragma once
#include "include/laboratory 1/IPrinter.hpp"

class SimplePrinter : public IPrinter
{
public:
	SimplePrinter() = default;
	~SimplePrinter() = default;
	void print_document(std::string_view text) override;
private:
	size_t printed_pages_count{};
};