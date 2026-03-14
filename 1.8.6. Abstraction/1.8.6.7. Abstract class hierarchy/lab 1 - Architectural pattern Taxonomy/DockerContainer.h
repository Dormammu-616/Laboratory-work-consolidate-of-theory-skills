#pragma once
#include "AbstractContainer.h"

class DockerContainer : public AbstractContainer
{
public:
	void deploy() override;
	void destroy() override;
};