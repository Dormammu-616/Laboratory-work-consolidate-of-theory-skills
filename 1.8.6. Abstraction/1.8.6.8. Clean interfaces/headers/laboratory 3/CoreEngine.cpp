#include <laboratory 3/IEngine.h>
#include <iostream>

class CoreEngine : public IEngine
{
public:
	CoreEngine() = default;
	void initialize() override;
	void execute_task(std::string_view task_name) override;
	~CoreEngine() = default;
private:
	std::string internal_version{"vers 1.0"};
	double physics_matrix[100]{1.1};
	//double physics_matrix[10000]{ 1.1 };	// äëÿ ýêñïåðèìåíòà
	//const size_t cylinder_count{ 6 };		// äëÿ ýêñïåðèìåíòà
	bool is_warmed_up{ false };
};

void CoreEngine::initialize()
{
	std::cout << std::boolalpha;

	std::cout << "[CoreEngine] Version: '" << internal_version << "', first elem matrix '" << physics_matrix[0] << "'.\n";
	//std::cout << "[CoreEngine] Data experiment:\n"
	//	<< "\tversion - "<< internal_version << "\n"
	//	<< "\tfirst elem matrix - " << physics_matrix[0] << "\n"
	//	<< "\tcylinder count - " << cylinder_count << "\n"; // äëÿ ýêñïåðèìåíòà

	is_warmed_up = true;
	std::cout << "[CoreEngine] Is warmed up? " << is_warmed_up << "\n";
	std::cout << std::noboolalpha;
}

void CoreEngine::execute_task(std::string_view task_name)
{
	std::cout << "[CoreEngine] Executed task '" << task_name << "'\n";
}

std::unique_ptr<IEngine> create_engine(std::string_view engine_type)
{
	if (engine_type == "core")
	{
		std::cout << "[unique_ptr<IEngine>] Type is '"<< engine_type << "'.\n";
		return std::make_unique<CoreEngine>();
	}
	else
	{
		std::cout << "[unique_ptr<IEngine>] Type is 'NULLPTR'.\n";
		return nullptr;
	}
}
