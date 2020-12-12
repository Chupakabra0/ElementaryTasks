//
// Created by Александр Сафиюлин on 09.12.2020.
//

#include "Triangle.hpp"

task::third::Triangle::Triangle(const std::string &name,
								const double firstSide,
								const double secondSide,
								const double thirdDouble)
	: Shape(name), firstSide_(firstSide), secondSide_
	(secondSide), thirdSide_(thirdDouble) {}

std::unique_ptr<task::third::Triangle> task::third::Triangle::CreateUniquePtrTriangle(
	const std::string & name,
	const double firstSide,
	const double secondSide,
	const double thirdSide) {
  std::unique_ptr<Triangle> triangle;
  if (firstSide < secondSide + thirdSide && secondSide < firstSide
	  + thirdSide && thirdSide < firstSide + secondSide) {
	triangle = std::unique_ptr<Triangle>(new(std::nothrow)
											 Triangle(name,
													  firstSide,
													  secondSide,
													  thirdSide));
  } else {
	std::cerr << std::endl << "This triangle doesn't exist..." <<
			  std::endl;
  }
  return triangle;
}

double task::third::Triangle::GetPerimeter() const {
  return this->firstSide_ + this->secondSide_ + this->thirdSide_;
}

double task::third::Triangle::GetSquare() const {
  auto halfPerimeter = this->GetPerimeter() / 2.0;
  return std::sqrt(
	  halfPerimeter * (halfPerimeter - this->firstSide_) *
		  (halfPerimeter - this->secondSide_) *
		  (halfPerimeter - this->thirdSide_));
}

bool task::third::operator<(const task::third::Triangle &first,
							const task::third::Triangle &second) {
  if (std::abs(first.GetSquare() - second.GetSquare()) <
	  std::numeric_limits<double>::epsilon()) {
	if (std::abs(first.firstSide_ - second.firstSide_) <
		std::numeric_limits<double>::epsilon()) {
	  if (std::abs(first.secondSide_ - second.secondSide_) <
		  std::numeric_limits<double>::epsilon()) {
		if (std::abs(first.thirdSide_ - second.thirdSide_) <
			std::numeric_limits<double>::epsilon()) {
		  if (first.name_ < second.name_) {
			return true;
		  }
		}
		if (first.thirdSide_ < second.thirdSide_) {
		  return true;
		}
	  }
	  if (first.secondSide_ < second.secondSide_) {
		return true;
	  }
	}
	if (first.firstSide_ < second.firstSide_) {
	  return true;
	}
  }
  if (first.GetSquare() < second.GetSquare()) {
	return true;
  }

  return false;
}

bool task::third::operator>(const Triangle &first,
							const Triangle &second) {
  return second < first;
}

bool task::third::operator>=(const Triangle &first,
							 const Triangle &second) {
  return !(first < second);
}

bool task::third::operator<=(const Triangle &first,
							 const Triangle &second) {
  return !(first > second);
}

bool task::third::operator==(const Triangle &first,
							 const Triangle &second) {
  return first <= second && first >= second;
}

bool task::third::operator!=(const Triangle &first,
							 const Triangle &second) {
  return !(first == second);
}