#pragma once
#include "Lab3/NetworkProcessor.hpp"

class HttpProcessor : public NetworkProcessor
{
public:
	~HttpProcessor() override = default;
private:
	void handle_payload() const override final;
};