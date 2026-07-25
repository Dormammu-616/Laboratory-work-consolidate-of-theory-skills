#include "lab1/UserRecord.hpp"
#include "lab1/TransactionRecord.hpp"
#include "lab1/DataExporter.hpp"
//#include "lab1/SystemState.hpp"
#include "lab2/AlgorithmRouter.hpp"
#include "lab2/ExecutionEngine.hpp"
#include <iostream>
#include <list>
#include <vector>

int main()
{
	std::cout << "*** Start laboratory #1 - Zero-Overhead Contracts ***\n";
	{
		lab1::UserRecord user_record{"first_obj", 5};
		lab1::TransactionRecord transaction_record{ 4.9, "dollars" };

		lab1::export_to_json(user_record);
		lab1::export_to_json(transaction_record);

		//lab1::SystemState sys_state{ 17 };
		//lab1::export_to_json(sys_state); // ОШИБКА C2672 "lab1::export_to_json": не найдена соответствующая перегруженная функция"
	}
	std::cout << "*** End laboratory #1 ***\n\n";

	std::cout << "*** Start laboratory #2 - Intelligent routing and standard concepts ***\n";
	{
		std::list<size_t> list{0, 1, 2, 3, 4, 5};
		std::vector<size_t> vec{11, 12, 13, 14, 15, 16, 17, 18, 19};

		auto it_begin_list{ list.begin() };
		auto it_begin_vec{ vec.begin() };

		lab2::advance_cursor(it_begin_list, 2);
		lab2::advance_cursor(it_begin_vec, 4);

		auto lambda_for_process{ [](size_t val) { std::cout << "\tProcessing the value '"<< val <<"' in a lambda expression.\n"; } };
		lab2::JobDispatcher::execute_callback(5, lambda_for_process);
	}
	std::cout << "*** End laboratory #2 ***\n\n";


	std::cout << "*** Start laboratory #3 -  ***\n";
	{
		
	}
	std::cout << "*** End laboratory #3 ***\n\n";

	return 0;
}