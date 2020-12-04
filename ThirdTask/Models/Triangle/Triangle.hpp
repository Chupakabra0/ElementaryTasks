//
// Created by Александр Сафиюлин on 04.12.2020.
//

#ifndef THIRDTASK_TRIANGLE_HPP
#define THIRDTASK_TRIANGLE_HPP

#include <algorithm>
#include "../Base/Shape.hpp"

namespace task::third
{
	class Triangle : public Shape
	{
	public:
		Triangle() = delete;

		Triangle(const Triangle&) = default;

		Triangle(Triangle&&) = default;

		[[nodiscard]] double GetPerimeter() const override
		{
			return this->firstSide_ + this->secondSide_ + this->thirdSide_;
		}

		[[nodiscard]] double GetSquare() const override
		{
			auto halfPerimeter = this->GetPerimeter() / 2.0;
			return std::sqrt(
					halfPerimeter * (halfPerimeter - this->firstSide_) *
					(halfPerimeter - this->secondSide_) *
					(halfPerimeter - this->thirdSide_));
		}

		static std::unique_ptr<Triangle> CreateUniquePtrTriangle
		(const std::string& name, double firstSide, double secondSide, double
		thirdSide) {
			std::unique_ptr<Triangle> triangle;
			if (firstSide < secondSide + thirdSide && secondSide < firstSide
			+ thirdSide && thirdSide < firstSide + secondSide) {
				triangle = std::unique_ptr<Triangle>(new(std::nothrow)
				Triangle(name, firstSide, secondSide, thirdSide));
			}
			else {
				std::cerr << std::endl << "This triangle doesn't exist..." <<
				std::endl;
			}
			return triangle;
		}

		friend bool operator<(
				const Triangle& first, const Triangle& second)
		{
			if (std::abs(first.GetSquare() - second.GetSquare()) <
				std::numeric_limits<double>::epsilon())
			{
				if (std::abs(first.firstSide_ - second.firstSide_) <
					std::numeric_limits<double>::epsilon())
				{
					if (std::abs(first.secondSide_ - second.secondSide_) <
						std::numeric_limits<double>::epsilon())
					{
						if (std::abs(first.thirdSide_ - second.thirdSide_) <
							std::numeric_limits<double>::epsilon())
						{
							if (first.name_ < second.name_)
							{
								return true;
							}
						}
						if (first.thirdSide_ < second.thirdSide_)
						{
							return true;
						}
					}
					if (first.secondSide_ < second.secondSide_)
					{
						return true;
					}
				}
				if (first.firstSide_ < second.firstSide_)
				{
					return true;
				}
			}
			if (first.GetSquare() < second.GetSquare())
			{
				return true;
			}

			return false;
		}

		friend bool operator>(const Triangle& first, const Triangle& second) {
			return second < first;
		}

		friend bool operator>=(const Triangle& first, const Triangle& second) {
			return !(first < second);
		}

		friend bool operator<=(const Triangle& first, const Triangle& second) {
			return !(first > second);
		}

		friend bool operator==(const Triangle& first, const Triangle& second) {
			return first <= second && first >= second;
		}

		friend bool operator!=(const Triangle& first, const Triangle& second) {
			return !(first == second);
		}

		template<class OstreamType>
		friend std::basic_ostream<OstreamType>& operator<<(std::basic_ostream<OstreamType>&
		        out, const Triangle& triangle) {
			return out << "[" << triangle.name_ << "]:" << " " << triangle
			.GetSquare();
		}

		~Triangle() override = default;

	protected:

		explicit Triangle(
				const std::string& name, const double firstSide,
				const double secondSide, const double thirdDouble)
				: Shape(name), firstSide_(firstSide), secondSide_
				(secondSide), thirdSide_(thirdDouble)
		{}

		double firstSide_;
		double secondSide_;
		double thirdSide_;
	};
}

#endif //THIRDTASK_TRIANGLE_HPP
