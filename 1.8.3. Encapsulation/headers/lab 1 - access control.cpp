#include "lab 1 - access control.h"
#include <iostream>

void Control::run_lab()
{
	std::cout << "***\tLab # 1 - Access control\t***";

    check_correct_operation();
    check_nocorrect_operation();
    check_operation_after_deactivation();
    check_protected_method_of_inheritor();

	std::cout << "\n***\tThe end labs #1\t***\n\n";
}

void Control::check_correct_operation()
{
    std::cout << "\n--- correct operation ---\n";

    std::cout << "\tfor account:\n";
    std::cout << "\t\toperation withdraw:\t" << ((Gregs_acc.withdraw(VALID_VAL)) ? ("SUCCESS") : ("FAILURE")) << "\n";
    std::cout << "\t\toperation deposit:\t" << ((Gregs_acc.deposit(VALID_VAL)) ? ("SUCCESS") : ("FAILURE")) << "\n";

    std::cout << "\tfor corporation account:\n";
    std::cout << "\t\toperation withdraw:\t" << ((Bills_corp_acc.withdraw(VALID_VAL)) ? ("SUCCESS") : ("FAILURE")) << "\n";
    std::cout << "\t\toperation deposit:\t" << ((Bills_corp_acc.deposit(VALID_VAL)) ? ("SUCCESS") : ("FAILURE")) << "\n";
}

void Control::check_nocorrect_operation()
{
    std::cout << "\n--- nocorrect operation ---\n";

    std::cout << "\tfor account withdraw:\t\t" << ((!Gregs_acc.withdraw(NOVALID_VAL)) ? ("SUCCESS") : ("FAILURE")) << "\n";
    std::cout << "\tfor corp account withdraw:\t" << ((!Bills_corp_acc.withdraw(NOVALID_VAL)) ? ("SUCCESS") : ("FAILURE"));
}

void Control::check_operation_after_deactivation()
{
    std::cout << "\n--- deactivation account and transaction verification---\n";

    std::cout << "\tdeactivation for account:\t" << ((Gregs_acc.deactivate()) ? ("SUCCESS") : ("FAILURE")) << "\n";
    std::cout << "\t\toperation withdraw:\t" << ((Gregs_acc.withdraw(VALID_VAL)) ? ("SUCCESS") : ("FAILURE")) << "\n";
    std::cout << "\t\toperation deposite:\t" << (( Gregs_acc.deposit(VALID_VAL)) ? ("SUCCESS") : ("FAILURE")) << "\n";
    std::cout << "\t\toperation deactivation:\t" << ((Gregs_acc.deactivate()) ? ("SUCCESS") : ("FAILURE")) << "\n";

    std::cout << "\tdeactivation for corp account:\t" << ((Bills_corp_acc.deactivate()) ? ("SUCCESS") : ("FAILURE")) << "\n";
    std::cout << "\t\toperation withdraw:\t" << ((Bills_corp_acc.withdraw(VALID_VAL)) ? ("SUCCESS") : ("FAILURE")) << "\n";
    std::cout << "\t\toperation deposite:\t" << ((Bills_corp_acc.deposit(VALID_VAL)) ? ("SUCCESS") : ("FAILURE")) << "\n";
    std::cout << "\t\toperation deactivation:\t" << ((Bills_corp_acc.deactivate()) ? ("SUCCESS") : ("FAILURE")) << "\n";
}

void Control::check_protected_method_of_inheritor()
{
    std::cout << "\n--- check protected method---\n";
    std::cout << "\tcorp account activation:\t" << ((Bills_corp_acc.activate()) ? ("SUCCESS") : ("FAILURE")) << "\n";
    std::cout << "\tcall protected method:\t\t" << ((Bills_corp_acc.apply_bonus_account()) ? ("SUCCESS") : ("FAILURE")) << "\n";
}