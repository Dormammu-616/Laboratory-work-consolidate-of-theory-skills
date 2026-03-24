#pragma once
#include "Account.h"
#include "CorporateAccount.h"

class Control
{
public:
	void run_lab();
private:
    Account Gregs_acc{ "Greg", 100 };
    CorparateAccount Bills_corp_acc{ "Bill", 50, 200 };
    const size_t VALID_VAL{ 10 };
    const size_t NOVALID_VAL{10000};
    void check_correct_operation();
    void check_nocorrect_operation();
    void check_operation_after_deactivation();
    void check_protected_method_of_inheritor();
};