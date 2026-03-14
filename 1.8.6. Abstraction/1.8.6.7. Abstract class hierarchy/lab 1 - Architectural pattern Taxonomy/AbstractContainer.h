#pragma once
#include "AbstractComputeInstance.h"

class AbstractContainer : public AbstractComputeInstance // осталось 2 долга: deploy и destroy
{
public:
	double getHourlyRate() override;
};