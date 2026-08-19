#include "lab2/ImageBuffer.hpp"
#include <iostream>
#include <utility>
#include <algorithm>

lab2::ImageBuffer::~ImageBuffer()
{
	std::cout << "[~ImageBuffer] Call destructor. Address before '" << static_cast<void*>(pixels_) << "', ";

	size_ = 0;
	delete[]pixels_;
	pixels_ = nullptr;

	std::cout << "address after '"<< static_cast<void*>(pixels_) <<"'\n";
}

lab2::ImageBuffer::ImageBuffer(size_t size) : size_(size), pixels_(new uint8_t[size_])
{
	std::cout << "[ImageBuffer(size)] Calling the constructor with the size '"<< size << "' and address '"<< static_cast<void*>(pixels_) << "'\n\n";
}

lab2::ImageBuffer::ImageBuffer(const lab2::ImageBuffer& other) : size_(other.size_), pixels_(new uint8_t[other.size_])
{
	std::cout << "[ImageBuffer(constImageBuffer&)] Call of the copy constructor by size '"<< other.size_ << "'.\n"
		<< "\taddress before of the operation:\n\taddress target '" << static_cast<void*>(pixels_) << "' address source '" << static_cast<void*>(other.pixels_) << "'\n";

	std::cout << "\t---copying...---\n";
	std::copy(other.pixels_, other.pixels_ + other.size_, pixels_);

	std::cout << "\taddress after of the operation:\n\taddress target '" << static_cast<void*>(pixels_) << "' address source '" << static_cast<void*>(other.pixels_) << "'\n\n";
}

lab2::ImageBuffer& lab2::ImageBuffer::operator=(const lab2::ImageBuffer& other)
{
	std::cout << "[operator=(constImageBuffer&)] Call of the assignment operator.\n";

	if (this == &other)
	{
		std::cout << "Error: attempted self-assignment!\n";
		return *this;
	}

	delete[]pixels_;

	size_ = other.size_;
	pixels_ = new uint8_t[size_];

	std::cout << "\taddress before of the operation:\n\taddress target '" << static_cast<void*>(pixels_) << "' address source '" << static_cast<void*>(other.pixels_) << "'\n";

	std::cout << "\t---copying...---\n";
	std::copy(other.pixels_, other.pixels_ + other.size_, pixels_);

	std::cout << "\taddress after of the operation:\n\taddress target '" << static_cast<void*>(pixels_) << "' address source '" << static_cast<void*>(other.pixels_) << "'\n\n";
	return *this;
}

lab2::ImageBuffer::ImageBuffer(lab2::ImageBuffer&& other) noexcept : size_(std::exchange(other.size_, 0)), pixels_(std::exchange(other.pixels_, nullptr))
{
	std::cout << "[ImageBuffer(ImageBuffer&&)] Call move constructor.\n"
		<<"\tAddress after of operation: target '" << static_cast<void*>(pixels_) << "' source '" << static_cast<void*>(other.pixels_) << "'\n\n";
}

lab2::ImageBuffer& lab2::ImageBuffer::operator=(lab2::ImageBuffer&& other) noexcept
{
	std::cout << "[operator=(ImageBuffer&&)] Call of the move operator.\n"
		<< "\taddress before of the operation:\n\taddress target '" << static_cast<void*>(pixels_) << "' address source '" << static_cast<void*>(other.pixels_) << "'\n";

	if (this == &other)
	{
		std::cout << "Error: attempted self-assignment!\n";
		return *this;
	}

	delete[]pixels_;

	size_ = std::exchange(other.size_, 0);
	pixels_ = std::exchange(other.pixels_, nullptr);

	std::cout << "\taddress after of the operation:\n\taddress target '" << static_cast<void*>(pixels_) << "' address source '" << static_cast<void*>(other.pixels_) << "'\n\n";

	return *this;
}