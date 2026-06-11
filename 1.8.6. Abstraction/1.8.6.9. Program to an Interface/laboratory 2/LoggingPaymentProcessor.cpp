#include <laboratory 2/LoggingPaymentProcessor.hpp>
#include <iostream>

LoggingPaymentProcessor::LoggingPaymentProcessor(std::shared_ptr<IPaymentProcessor> payment) : m_wrappee(payment) {};

bool LoggingPaymentProcessor::process_payment(const double amount)
{
	std::cout << "[Log] Starting to process a payment to '"<< amount << "'$.\n";
	const bool IS_SUCCESSFUL_PAYMENT{ m_wrappee->process_payment(amount) };

	std::cout << std::boolalpha;
	std::cout << "[Log] Payment completed. Status: '"<< IS_SUCCESSFUL_PAYMENT << "'.\n";
	std::cout << std::noboolalpha;
	return IS_SUCCESSFUL_PAYMENT;
}