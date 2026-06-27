#pragma once
#include "Lab3/NetworkProcessor.hpp"

class FtpProcessor final : public NetworkProcessor
{
public:
	~FtpProcessor() override = default;
private:
	void handle_payload() const override;
};
