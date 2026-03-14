#include "AbstractLocalModel.h"
#include <iostream>
#include <stdexcept>

AbstractLocalModel::AbstractLocalModel(const std::string& model, const int size)
{
	if (model == "" || size <= 0)
	{
		throw std::invalid_argument("incorrect data for creating AbstractLocalModel.\n");
	}

	model_path = model;
	batch_size = size;
}

void AbstractLocalModel::load_model()
{
	is_loaded = true;
	std::cout << "path: " << model_path << "\n";
}

size_t AbstractLocalModel::get_VRAM_usage() const
{
	return batch_size * 1024;
}