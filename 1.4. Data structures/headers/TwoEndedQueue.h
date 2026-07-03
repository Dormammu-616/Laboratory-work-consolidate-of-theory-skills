#pragma once
#include <OrderTask.h>
#include <deque>

class TwoEndedQueue
{
public:
	TwoEndedQueue() = default;
	~TwoEndedQueue() = default;
	void push_front(const OrderTask& data);
	void push_back(const OrderTask& data);
	void pop_front();
	void pop_back();
	const OrderTask& peek_front() const;
	const OrderTask& peek_back() const;
	bool is_empty() const;
	size_t size() const;
private:
	std::deque<OrderTask> internal_queue{};
};