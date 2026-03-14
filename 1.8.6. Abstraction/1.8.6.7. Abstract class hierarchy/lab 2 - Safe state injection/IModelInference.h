#pragma once
#include <string>

class IModelInference
{
public:
	virtual void load_model() = 0;
	virtual void predict(std::string input) = 0;
	virtual size_t get_VRAM_usage() const = 0;
	virtual ~IModelInference() = default;
};