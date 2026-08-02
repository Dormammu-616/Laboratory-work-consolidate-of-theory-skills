#pragma once

namespace lab3
{
	class SecureBuffer
	{
	public:
		explicit SecureBuffer(size_t size);
		~SecureBuffer();
		SecureBuffer(const SecureBuffer& other);
		SecureBuffer(SecureBuffer&& other) noexcept;
		void swap(SecureBuffer& other) noexcept;
		SecureBuffer& operator=(SecureBuffer other) noexcept;
		size_t size() const noexcept;
		char get_first_char() const noexcept;
	private:
		char* data_{ nullptr };
		size_t size_{ 0 };
		const char* data() const noexcept;
	};
}