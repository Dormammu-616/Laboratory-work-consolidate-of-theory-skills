#pragma once
#include <cstdint>

namespace lab2
{
	class ImageBuffer
	{
	public:
		ImageBuffer() = default;
		~ImageBuffer();
		ImageBuffer(size_t size);
		ImageBuffer(const ImageBuffer& other);
		ImageBuffer& operator=(const ImageBuffer& other);
		ImageBuffer(ImageBuffer&& other) noexcept;
		ImageBuffer& operator=(ImageBuffer&& other) noexcept;
	private:
		size_t size_{ 0 };
		uint8_t* pixels_{ nullptr };
	};
}