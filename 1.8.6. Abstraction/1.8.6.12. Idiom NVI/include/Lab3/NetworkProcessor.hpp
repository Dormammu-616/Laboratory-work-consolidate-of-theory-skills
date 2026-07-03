#pragma once

class NetworkProcessor
{
public:
	virtual ~NetworkProcessor() = default;
	void process_request();
private:
	virtual void handle_payload() const = 0;
};