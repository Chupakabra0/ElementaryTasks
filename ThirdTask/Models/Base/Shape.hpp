//
// Created by Александр Сафиюлин on 04.12.2020.
//

#ifndef THIRDTASK_SHAPE_HPP
#define THIRDTASK_SHAPE_HPP

#include <iostream>
#include <string>

namespace task::third
{
	class Shape
	{
	public:
		Shape() = delete;

		explicit Shape(const std::string& name) : name_(name)
		{};

		Shape(const Shape&) = default;

		Shape(Shape&&) = default;

		[[nodiscard]] std::string GetName() const
		{
			return this->name_;
		}

		void SetName(const std::string& string)
		{
			if (this->name_ == string)
			{
				return;
			}
			this->name_ = string;
		}

		virtual double GetPerimeter() const = 0;

		virtual double GetSquare() const = 0;

		virtual ~Shape() = default;

	protected:
		std::string name_;
	};
}

#endif //THIRDTASK_SHAPE_HPP
