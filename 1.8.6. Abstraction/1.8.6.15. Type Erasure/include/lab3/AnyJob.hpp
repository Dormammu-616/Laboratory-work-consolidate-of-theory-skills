#pragma once
#include <memory>
#include <iostream>

namespace lab3
{
	class AnyJob
	{
	public:
		AnyJob(const AnyJob& other) : pimpl_(other.pimpl_ ? other.pimpl_->clone() : nullptr) {};
		AnyJob& operator=(AnyJob job) noexcept
		{
			pimpl_.swap(job.pimpl_);
			return *this;
		}
		AnyJob(AnyJob&&) = default;
		template <typename T> AnyJob(T obj) : pimpl_(std::make_unique<Model<T>>(std::move(obj))) {};
		bool execute()
		{
			std::cout << "[AnyJob] Execution...\n";
			return pimpl_->execute();
		}
	private:
		struct Concept
		{
			virtual ~Concept() = default;
			virtual bool execute() = 0;
			virtual std::unique_ptr<Concept> clone() const = 0;
		};

		template <typename T>
		struct Model final : public Concept
		{
			T data;
			explicit Model(T obj) : data(std::move(obj)) {};

			bool execute() override
			{
				std::cout << "\t[Model] Execution...\n";
				return data.execute();
			}
			std::unique_ptr<Concept> clone() const override
			{
				std::cout << "\t[Model] Cloning...\n";
				return std::make_unique<Model<T>>(*this);
			}
		};

		std::unique_ptr<Concept> pimpl_{};
	};
}