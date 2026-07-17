#pragma once
#include <memory>
#include <iostream>

namespace lab2
{
	class AnySimulatable
	{
	public:
		template <typename T> AnySimulatable(T obj) : pimpl_(std::make_unique<Model<T>>(std::forward<T>(obj))) {};
		~AnySimulatable() = default;
		AnySimulatable(AnySimulatable&&) = default;
		AnySimulatable(const AnySimulatable& obj)
		{
			if (obj.pimpl_ != nullptr)
			{
				pimpl_ = obj.pimpl_->clone();
			}
		}
		AnySimulatable& operator=(AnySimulatable obj) noexcept
		{
			pimpl_.swap(obj.pimpl_);
			return *this;
		}
		void simulate() const
		{
			std::cout << "[AnySimulatable] Simulate obj...\n";
			pimpl_->simulate();
		}
	private:
		struct Concept
		{
			virtual ~Concept() = default;
			virtual void simulate() const = 0;
			virtual std::unique_ptr<Concept> clone() const = 0;
		};

		template <typename T>
		struct Model final : public Concept
		{
			T data;
			explicit Model(T obj) : data(std::move(obj)) {};

			void simulate() const override
			{
				std::cout << "\t[Model<T>] Simulate...\n";
				data.simulate();
			}
			std::unique_ptr<Concept> clone() const override
			{
				std::cout << "\t[Model<T>] Cloning...\n";
				return std::make_unique<Model<T>>(*this);
			}
		};

		std::unique_ptr<Concept> pimpl_{};
	};
}