#pragma once
#include "AbstractLocalModel.h"

class LLMTextModel : public AbstractLocalModel
{
public:
	LLMTextModel() = delete;
	LLMTextModel(const std::string& path, const int size_batch);
	void predict(std::string input) override;
};