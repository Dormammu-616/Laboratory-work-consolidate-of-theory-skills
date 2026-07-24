#include "lab1/UserRecord.hpp"
#include "lab1/TransactionRecord.hpp"
#include "lab1/DataExporter.hpp"
//#include "lab1/SystemState.hpp"
#include <iostream>

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

	std::cout << "*** Start laboratory #2 -  ***\n";
	{
		
	}
	std::cout << "*** End laboratory #2 ***\n\n";


	std::cout << "*** Start laboratory #3 -  ***\n";
	{
		
	}
	std::cout << "*** End laboratory #3 ***\n\n";

	return 0;
}