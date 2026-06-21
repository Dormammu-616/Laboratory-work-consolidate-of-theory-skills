#include "include/laboratory 1/PostgreSQLCustomerRepository.hpp"
#include "include/laboratory 1/LoanCalculator.hpp"
#include "include/laboratory 1/MockCustomerRepository.hpp"
#include "include/laboratory 2/TwilioApi.hpp"
#include "include/laboratory 2/TwilioNotifierAdapter.hpp"
#include "include/laboratory 2/UserManager.hpp"
#include "include/laboratory 3/CreditCardPayment.hpp"
#include "include/laboratory 3/CryptoPayment.hpp"
#include "include/laboratory 3/OrderCheckout.hpp"
#include <iostream>
#include <memory>

int main()
{
    std::cout << "*** Start laboratory #1 - Isolating business logic from infrastructure ***\n";
    auto p_postgre_repository{ std::make_shared<Infrastructure::PostgreSQLCustomerRepository>()};
    BusinessLogic::LoanCalculator postgre_calculator{ p_postgre_repository };
    postgre_calculator.assess_loan_application("ID-101");

    auto p_mock_repository{ std::make_shared<Infrastructure::MockCustomerRepository>() };
    BusinessLogic::LoanCalculator mock_calculator{ p_mock_repository };
    mock_calculator.assess_loan_application("ID-101");
    std::cout << "*** End laboratory #1 ***\n\n";


    std::cout << "*** Start laboratory #2 - AdapterDIP ***\n";
    auto api{ std::make_shared<ExternalVendor::TwilioApi>() };
    auto adapter{ std::make_shared<Infrastructure::TwilioNotifierAdapter>(api, "+1-555-555-0199") };
    BusinessLogic::UserManager manager{ adapter};
    manager.register_user("Alice");
    std::cout << "*** End laboratory #2 ***\n\n";


    std::cout << "*** Start laboratory #3 - DynamicStrategyDIP ***\n";
    auto card_payment{ std::make_shared<PaymentGateways::CreditCardPayment>() };
    auto crypto_payment{ std::make_shared<PaymentGateways::CryptoPayment>() };
    BusinessLogic::OrderCheckout order{ card_payment };
    order.checkout(150.50);

    order.change_payment_method(crypto_payment);
    order.checkout(99.99);

    std::cout << "*** End laboratory #3 ***\n";
}