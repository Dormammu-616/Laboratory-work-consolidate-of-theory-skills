#include "lab 1 - access control.h"
#include "lab 2 - idiom PIMPL.h"
#include "lab 3 - Stable Public API.h"

int main()
{
    // лабораторная #1 - управление доступом
    Control lab_control{};
    lab_control.run_lab();

    // лабораторная #2 -
    Idiom_PIMPL lab_pimpl{};
    lab_pimpl.run_lab();  

    // лабораторная #3 - 
    Stable_Public_API api{};
    api.run_lab();

    return 0;
}
