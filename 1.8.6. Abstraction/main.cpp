#include "laboratory 1/OrderService.hpp"
#include "laboratory 1/MySQLRepository.hpp"
#include "laboratory 1/MemoryRepository.hpp"
#include "laboratory 2/StripePaymentProcessor.hpp"
#include "laboratory 2/LoggingPaymentProcessor.hpp"
#include "laboratory 2/StoreCheckout.hpp"
#include "laboratory 3/JsonExportStrategy.hpp"
#include "laboratory 3/CsvExportStrategy.hpp"
#include "laboratory 3/ReportManager.hpp"
#include <iostream>


int main()
{
    std::cout << "*** Start laboratory #1 - Dependency breaking and dependency injection ***\n";
    auto sql_repository{ std::make_shared<MySQLRepository>()};
    OrderService sql_service{ sql_repository };
    sql_service.process_new_order("cost banana");

    auto memory_repository{ std::make_shared<MemoryRepository>() };
    OrderService memory_service{ memory_repository };
    memory_service.process_new_order("buy apple");
    std::cout << "*** End laboratory # 1 ***\n\n";


    std::cout << "*** Start laboratory # 2 - ***\n";
    auto stripe_payment{ std::make_shared<StripePaymentProcessor>() };
    auto payment_process{ std::make_shared<LoggingPaymentProcessor>(stripe_payment) };
    StoreCheckout store{ payment_process };
    store.checkout_cart(47.5);
    std::cout << "*** End laboratory # 2 ***\n\n";


    std::cout << "*** Start laboratory # 3 - ***\n";
    auto json_strategy{ std::make_shared<JsonExportStrategy>() };
    auto csv_strategy{ std::make_shared<CsvExportStrategy>() };
    ReportManager report{ json_strategy };
    report.generate_report("Financial report for may");
    report.set_strategy(csv_strategy);
    report.generate_report("Financial report for june");
    std::cout << "*** End laboratory # 3 ***\n\n";

    return 0;
}
