#include "lab1/CryptoBuffer.hpp"
#include <iostream>

lab1::CryptoBuffer::CryptoBuffer(size_t size) : size_(size), data_(new uint8_t[size])
{
	std::cout << "[CryptoBuffer] Constructor called with size '"<< size_ << "'. Memory allocated.\n";
}

lab1::CryptoBuffer::~CryptoBuffer()
{
	delete []data_;
	data_ = nullptr;
	
	std::cout << "[CryptoBuffer] Destructor called - memory freed.\n";
}

lab1::CryptoBuffer::CryptoBuffer(const lab1::CryptoBuffer& other) : size_(other.size_), data_(new uint8_t[other.size_])
{
	std::cout << "[CryptoBuffer] Copy constructor called.\n";

	std::copy(other.data_, other.data_ + other.size_, data_);
}

lab1::CryptoBuffer& lab1::CryptoBuffer::operator=(const lab1::CryptoBuffer& other)
{
	std::cout << "[CryptoBuffer] Copy assignment operator called.\n";

	if (this != &other)
	{
		uint8_t* new_data{ new uint8_t[other.size_] };
		std::copy(other.data_, other.data_ + other.size_, new_data);

		delete[] data_;

		size_ = other.size_;
		data_ = new_data;
	}

	return *this;
}

lab1::CryptoBuffer::CryptoBuffer(lab1::CryptoBuffer&& other) noexcept : data_(std::exchange(other.data_, nullptr)), size_(std::exchange(other.size_, 0))
{
	std::cout << "[CryptoBuffer] Move constructor called.\n";
}

lab1::CryptoBuffer& lab1::CryptoBuffer::operator=(lab1::CryptoBuffer&& other) noexcept
{
	std::cout << "[CryptoBuffer] Move assignment operator called.\n";

	if (this != &other)
	{
		delete[] data_;

		data_ = std::exchange(other.data_, nullptr);
		size_ = std::exchange(other.size_, 0);
	}

	return *this;
}

void lab1::CryptoBuffer::get_memory_address() const
{
	std::cout << "[CryptoBuffer] Getting memory address '"<< static_cast<void*>(data_) << "'.\n";
}