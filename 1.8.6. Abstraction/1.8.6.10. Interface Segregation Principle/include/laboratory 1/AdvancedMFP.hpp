#pragma once
#include "include/laboratory 1/IPrinter.hpp"
#include "include/laboratory 1/IScanner.hpp"
#include "include/laboratory 1/IFax.hpp"
#include <string>

class AdvancedMFP : public IPrinter, public IScanner, public IFax
{
public:
	AdvancedMFP(std::string_view name);
	~AdvancedMFP() = default;
	AdvancedMFP(const AdvancedMFP&) = delete;
	AdvancedMFP& operator=(const AdvancedMFP&) = delete;
	void print_document(std::string_view text) override;
	std::string scan_document() const override;
	void send_fax(std::string_view text, std::string_view number) override;
private:
	const std::string device_name{};
};
