#include <TwoEndedQueue.h>
#include <stdexcept>

void TwoEndedQueue::push_front(const OrderTask& data)
{
	internal_queue.emplace_front(data);
}

void TwoEndedQueue::push_back(const OrderTask& data)
{
	internal_queue.emplace_back(data);
}

void TwoEndedQueue::pop_front()
{
	if (internal_queue.empty())
	{
		throw std::out_of_range("attempt to remove an element from an empty queue!");
	}

	internal_queue.pop_front();
}

void TwoEndedQueue::pop_back()
{
	if (internal_queue.empty())
	{
		throw std::out_of_range("attempt to remove an element from an empty queue!");
	}

	internal_queue.pop_back();
}

const OrderTask& TwoEndedQueue::peek_front() const
{
	if (internal_queue.empty())
	{
		throw std::out_of_range("attempt to peek an element from an empty queue!");
	}

	return internal_queue.front();
}

const OrderTask& TwoEndedQueue::peek_back() const
{
	if (internal_queue.empty())
	{
		throw std::out_of_range("attempt to peek an element from an empty queue!");
	}

	return internal_queue.back();
}

bool TwoEndedQueue::is_empty() const
{
	return internal_queue.empty();
}

size_t TwoEndedQueue::size() const
{
	return internal_queue.size();
}