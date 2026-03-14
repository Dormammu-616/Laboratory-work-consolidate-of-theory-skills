#pragma once
#include "AbstractContainer.h"

class PodmanContainer : public AbstractContainer
{
public:
	void deploy() override;
	void destroy() override;
};