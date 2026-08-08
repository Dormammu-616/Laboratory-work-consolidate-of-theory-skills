#include "lab2/PacketAnalyzer.hpp"
#include <iostream>

lab2::PacketAnalyzer::PacketAnalyzer(lab2::SignatureScanner scanner) : scanner_(std::move(scanner)) {};

void lab2::PacketAnalyzer::analyze(const lab2::Packet& packet, std::string_view threat_signature) const
{
	std::cout << std::boolalpha;

	std::cout << "[PacketAnalyzer] Analysis string '"<< threat_signature << "' for packet:\n"
		<< "\tpayload '" << packet.get_view() << "'\n"
		<< "\tID value '" << packet.get_id() << "'\n";

	std::string_view header_view{ packet.extract_header(5) };
	std::string_view body_view{ packet.extract_body(5) };

	std::cout << "Contains signature in the header: '" << scanner_.is_contains(header_view, threat_signature) << "'\n";
	std::cout << "Contains signature in the body: '" << scanner_.is_contains(body_view, threat_signature) << "'\n";

	scanner_.print_hex_dump(header_view);
	scanner_.print_hex_dump(body_view);

	std::cout << std::noboolalpha;
}