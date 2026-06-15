#include "include/laboratory 1/SimplePrinter.hpp"
#include "include/laboratory 1/AdvancedMFP.hpp"
#include "include/laboratory 1/DocumentManager.hpp"
#include "include/laboratory 2/LegacyRobot.hpp"
#include "include/laboratory 2/RobotMoverAdapter.hpp"
#include "include/laboratory 2/LogisticsSystem.hpp"
#include "include/laboratory 3/CloudServer.hpp"
#include "include/laboratory 3/CloudClients.hpp"
#include <iostream>

void send_scanner_copy(IScanner& scanner, IFax& fax) // только для лабораторной работы #1
{
    std::cout << "[FreeFunc] Trying to use a scanner and fax...\n";
    scanner.scan_document();
    fax.send_fax("example text for fax", "+7845454");
}

int main()
{
    std::cout << "*** Start laboratory #1 - Decomposing a fat interface ***\n";
    SimplePrinter printer{};
    AdvancedMFP mfp{"ordinary MFP"};
    DocumentManager manager{};

    manager.process_print_job(printer, "example text for printer");
    manager.process_print_job(mfp, "example text for MFP");
    
    //send_scanner_copy(printer, printer); // ОШИБКА КОМПИЛЯЦИИ: невозможность преобразовать аргумент из-за принципа разделенного интерфейса
    std::cout << "*** End laboratory # 1 ***\n\n";


    std::cout << "*** Start laboratory #2 -  ***\n";
    LegacyRobot old_robot{};
    RobotMoverAdapter adapter{ old_robot };
    LogisticsSystem system{};
    system.route_shipment(adapter, "Warehouse a");
    std::cout << "*** End laboratory # 2 ***\n\n";


    std::cout << "*** Start laboratory #3 - Client-specific interface ***\n";
    CloudServer server{ "simple-server" };
    TaskScheduler scheduler{};
    TelemetryDashboard dashboard{};
    AdminConsole console_admin{};

    scheduler.assign_work(server, "read data");
    dashboard.collect_data(server);
    console_admin.restart_server(server);

    std::cout << "*** End laboratory # 3 ***\n\n";

    return 0;
}