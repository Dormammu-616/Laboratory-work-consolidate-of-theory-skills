#include "include/laboratory 1/DocumentManager.hpp"
#include <iostream>

void DocumentManager::process_print_job(IPrinter& printer, std::string_view document)
{
	std::cout << "[DocumentManager] Submitting a print job...\n";
	printer.print_document(document);
}