#pragma once
#include <lab1/FileDeleter.hpp>
#include <memory>
#include <cstdint>
#include <stdexcept>
#include <iostream>

namespace lab1
{
	class AuditFileHandle
	{
	public:
		AuditFileHandle(const AuditFileHandle&) = delete;
		AuditFileHandle(AuditFileHandle&&) = default;
		AuditFileHandle& operator= (const AuditFileHandle&) = delete;
		AuditFileHandle& operator=(AuditFileHandle&& other) noexcept = default;
		AuditFileHandle(FILE* file) : handle_(file)
		{
			if (file == nullptr)	throw std::runtime_error("Failed to open audit log file!");
		};
		~AuditFileHandle() = default;

		bool is_valid() const
		{
			std::cout << "[AuditFileHandle] Checking the validity of the file.\n";

			return (handle_ != nullptr);
		}

		size_t write(const void* data, size_t size)
		{
			std::cout << "[AuditFileHandle] Writing file...\n";

			if (!is_valid() || data == nullptr || size == 0) return 0;

			return std::fwrite(data, 1, size, handle_.get());
		}
	private:
		std::unique_ptr<FILE, lab1::FileDeleter> handle_{};
	};
}