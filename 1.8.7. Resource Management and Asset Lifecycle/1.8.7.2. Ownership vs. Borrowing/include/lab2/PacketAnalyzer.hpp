#pragma once
#include "lab2/SignatureScanner.hpp"
#include "lab2/Packet.hpp"

namespace lab2
{
	class PacketAnalyzer
	{
	public:
		PacketAnalyzer(lab2::SignatureScanner scanner);
		~PacketAnalyzer() = default;
		void analyze(const lab2::Packet& packet, std::string_view threat_signature) const;
	private:
		lab2::SignatureScanner scanner_;
	};
}