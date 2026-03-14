#include "LLMTextModel.h"
#include <iostream>

LLMTextModel::LLMTextModel(const std::string& path, const int size_batch) : AbstractLocalModel(path, size_batch) { std::cout << "\tLLMTextModel created!\n"; };

void LLMTextModel::predict(std::string input)
{
	(is_loaded == true) ? (std::cout << "success input '" << input << "'!\n") : (std::cout << "failed input!\n");
}