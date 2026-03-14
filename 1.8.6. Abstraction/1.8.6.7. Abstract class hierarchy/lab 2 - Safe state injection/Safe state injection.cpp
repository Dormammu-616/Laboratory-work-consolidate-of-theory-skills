#include "Safe state injection.h"
#include <iostream>
//#include "AbstractLocalModel.h"
#include "LLMTextModel.h"

void State_Injection::run_lab()
{
	std::cout << "*** Start lab #2 ***\n";

	// ОШИБКА КОМПИЛЯТОРА: создание экземпляра абстрактного класса невозможно
	//AbstractLocalModel incorrect_model{}; // остался 1 долг

	std::cout << "--- The created correct object ---\n";
	LLMTextModel correct_model("correct/new_model", 5);

	std::cout << "\n--- Calling methods correct object ---\n";
	std::cout << "\tload model = ";
	correct_model.load_model();
	std::cout << "\tpredict = ";
	correct_model.predict("sample");
	std::cout << "\tVRAM = " << correct_model.get_VRAM_usage() << "\n";
	
	std::cout << "\n--- Attempt to create an invalid object ---\n";
	try
	{
		LLMTextModel failed_object("", -5);
	}
	catch (std::invalid_argument& e)
	{
		std::cout << "\tERROR - " << e.what();
	}

	std::cout << "*** End lab #2 ***\n\n";
}