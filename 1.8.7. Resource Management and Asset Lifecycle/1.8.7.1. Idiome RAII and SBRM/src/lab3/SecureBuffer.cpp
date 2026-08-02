#include "lab3/SecureBuffer.hpp"
#include <iostream>
#include <algorithm>

lab3::SecureBuffer::SecureBuffer(size_t size)
{
	if (size != 0)
	{
		data_ = new char[size]();
		std::fill_n(data_, size, 'A');
		size_ = size;
		std::cout << "[SecureBuffer] Allocated buffer of size '"<< size <<"'.\n";
	}
}

lab3::SecureBuffer::~SecureBuffer()
{
	if (data_ != nullptr)
	{
		delete[] data_;
		data_ = nullptr;
		std::cout << "[SecureBuffer] Deallocated buffer.\n";
	}
}

lab3::SecureBuffer::SecureBuffer(const lab3::SecureBuffer& other)
{
	if (other.size_ != 0)
	{
		data_ = new char[other.size()];
		size_ = other.size_;
		std::copy(other.data_, other.data_ + other.size(), data_);
	}
	std::cout << "[SecureBuffer] Copy constructor called.\n";
}

lab3::SecureBuffer::SecureBuffer(lab3::SecureBuffer&& other) noexcept
{
	if (this != &other)
	{
		this->data_ = std::exchange(other.data_, nullptr);
		this->size_ = std::exchange(other.size_, 0);
		std::cout << "[SecureBuffer] Move constructor called.\n";
	}
}

void lab3::SecureBuffer::swap(lab3::SecureBuffer& other) noexcept
{
	if (this != &other)
	{
		std::swap(this->data_, other.data_);
		std::swap(this->size_, other.size_);
		std::cout << "[SecureBuffer] Swap() called.\n";
	}
}

lab3::SecureBuffer& lab3::SecureBuffer::operator=(lab3::SecureBuffer other) noexcept
{
	this->swap(other);
	std::cout << "[SecureBuffer] Copy operator called.\n";

	return *this;
}

const char* lab3::SecureBuffer::data() const noexcept
{
	return data_;
}

char lab3::SecureBuffer::get_first_char() const noexcept
{
	if (size_ != 0)
	{
		return data_[0];
	}

	return '\0';
}

size_t lab3::SecureBuffer::size() const noexcept
{
	return size_;
}