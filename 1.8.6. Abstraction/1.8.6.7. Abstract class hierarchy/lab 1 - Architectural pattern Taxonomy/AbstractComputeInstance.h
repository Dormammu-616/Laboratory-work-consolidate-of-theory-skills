#pragma once
#include "ICloudResource.h"

class AbstractComputeInstance : public ICloudResource	// осталось 3 долга
{
public:
	void start() override;
	void stop() override;
};