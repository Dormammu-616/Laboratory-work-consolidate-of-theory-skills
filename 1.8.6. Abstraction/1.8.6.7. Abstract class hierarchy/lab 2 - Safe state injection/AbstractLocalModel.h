#pragma once
#include "IModelInference.h"

class AbstractLocalModel : public IModelInference
{
public:
	void load_model() override;
	size_t get_VRAM_usage() const override;
protected:
	std::string model_path{};
	int batch_size{};
	bool is_loaded{};
	AbstractLocalModel() = delete;
	AbstractLocalModel(const std::string& model, const int size);
};