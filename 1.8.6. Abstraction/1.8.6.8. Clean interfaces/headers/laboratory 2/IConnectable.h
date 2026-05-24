#pragma once
#include <string>

class IConnectable
{
public:
	virtual void connect(std::string_view network) = 0;
	virtual void disconnect() = 0;
	virtual bool is_connected() const = 0;
	virtual ~IConnectable() = default;
};