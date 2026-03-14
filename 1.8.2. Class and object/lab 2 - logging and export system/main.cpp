#include <iostream>
#include "Participant.h"
#include "CompetitionLogger.h"
#include "CompetitionManager.h"

int main()
{
    std::cout << "*** The created class object participant ***\n";
    Participant alice{5, "Alice"};
    std::cout << alice;

    std::cout << "*** Call CompetitionLogger::log_deep_scan for class object participant ***\n";
    CompetitionLogger::log_deep_scan(alice);

    const size_t VALID_SCORE{ 1 };
    std::cout << "*** Creating an class object 'Competition Manager' with an VALID score value of '" << VALID_SCORE << "' ***\n";
    CompetitionManager manager_first{VALID_SCORE, "Bob"};

    const size_t NOT_VALID_SCORE{ 0 };
    std::cout << "\t\nThe adding a participant with an INVALID score value of '" << NOT_VALID_SCORE << "'.\n";
    manager_first.add_participant(NOT_VALID_SCORE, "Back");
    std::cout << "\n";
    std::cout << manager_first;

    std::cout << "*** Creating an class object 'Competition Manager' with an INVALID score value of '" << NOT_VALID_SCORE << "' ***\n";
    CompetitionManager manager_second(NOT_VALID_SCORE, "Claire");
    std::cout << manager_second;

    std::cout << "*** End of program operation ***\n";

    return 0;
}