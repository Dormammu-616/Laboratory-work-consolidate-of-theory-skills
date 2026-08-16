#include "lab1/RawNetworkBuffer.hpp"
#include <iostream>
#include <algorithm>

lab1::RawNetworkBuffer::RawNetworkBuffer(size_t size) : size_(size), data_(new uint8_t[size])
{
	std::cout << "[RawNetworkBuffer] Memory of '"<< size << "' bytes is allocated. ";

	for (uint8_t i = 0; i < size_; ++i)
	{
		data_[i] = i;
	}

	std::cout << "Address: " << static_cast<void*>(data_) << "\n";
}

lab1::RawNetworkBuffer::~RawNetworkBuffer()
{
	std::cout << "[RawNetworkBuffer] Clear buffer by address '" << static_cast<void*>(data_) <<"'.\n";

	delete[]data_;
	data_ = nullptr;
}

lab1::RawNetworkBuffer::RawNetworkBuffer(const lab1::RawNetworkBuffer& buffer) : size_(buffer.size_), data_(new uint8_t[buffer.size_])
{
	std::cout << "[RawNetworkBuffer] Call of the copy constructor for buffer of size '"<< buffer.size_ << "' by adress '" << static_cast<void*>(data_) << "'.\n";

	std::copy(buffer.data_, buffer.data_ + size_, data_);
}

lab1::RawNetworkBuffer& lab1::RawNetworkBuffer::operator=(const lab1::RawNetworkBuffer& other)
{
	std::cout << "[RawNetworkBuffer] Call of the assignment operator.\n"
		<< "\taddress of old memory being deleted:\t" << static_cast<void*>(data_) << "\n";

	if (this == &other)
	{
		std::cout << "[RawNetworkBuffer] Error: attempted self-assignment.\n";
		return *this;
	}

	delete[]data_;

	size_ = other.size_;
	data_ = new uint8_t[size_];

	std::copy(other.data_, other.data_ + size_, data_);

	std::cout << "\taddress of new allocated memory:\t" << static_cast<void*>(data_) << "\n";
	
	return *this;
}