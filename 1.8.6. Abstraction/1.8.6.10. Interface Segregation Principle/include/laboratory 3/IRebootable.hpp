#pragma once

class IRebootable
{
public:
	virtual void reboot() = 0;
	virtual ~IRebootable() = default;
};