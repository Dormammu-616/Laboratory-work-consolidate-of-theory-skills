#pragma once
#include <laboratory 2/IPaymentProcessor.hpp>
#include <memory>

class LoggingPaymentProcessor : public IPaymentProcessor
{
public:
	LoggingPaymentProcessor() = delete;
	LoggingPaymentProcessor(std::shared_ptr<IPaymentProcessor> payment);
	bool process_payment(const double amount) override;
	~LoggingPaymentProcessor() = default;
private:
	std::shared_ptr<IPaymentProcessor> m_wrappee;	
};