#include <iostream>
#include "CompetitionManager.h"

int main()
{
    std::cout << "Global count: " << Participant::get_live_objects_count() << "\n";

    {
        std::cout << "\n--- Scope start ---\n";
        
        CompetitionManager super_cup{ "Super Cup", 5 };
        super_cup.dispatch_participant("Alice");
        super_cup.dispatch_participant("Bob");

        std::cout << "\n--- Stack test ---\n";
        super_cup.perform_check_up();
    
        std::cout << "\n--- Score end ---\n";
    }

    std::cout << "\n--- End main ---\n";
    std::cout << "Global count: " << Participant::get_live_objects_count() << "\n";

    return 0;
}