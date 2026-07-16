#pragma once
#include <iostream>

namespace lab1
{
	class AnyRenderable
	{
	public:
		template<typename T> AnyRenderable(T&& obj) : pimpl_(std::make_unique<Model<T>>(std::forward<T>(obj))) {};
		AnyRenderable(const AnyRenderable&) = delete;
		AnyRenderable& operator=(const AnyRenderable&) = delete;
		AnyRenderable(AnyRenderable&&) = default;
		AnyRenderable& operator=(AnyRenderable&&) = default;
		~AnyRenderable() = default;

		void render() const
		{
			pimpl_->do_render();
		}
	private:
		struct Concept
		{
			virtual ~Concept() = default;
			virtual void do_render() const = 0;
		};

		template <typename T>
		struct Model final : public Concept
		{
			T data;
			explicit Model(T obj) : data(std::move(obj)) {};
			void do_render() const override
			{
				std::cout << "\t[Model<T>] Duck typing of the 'render' method.\n";
				data.render();
			}
		};
		std::unique_ptr<Concept> pimpl_;
	};
}