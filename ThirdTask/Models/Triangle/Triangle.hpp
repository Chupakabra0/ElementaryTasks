//
// Created by Александр Сафиюлин on 04.12.2020.
//

#pragma once

#ifndef THIRDTASK_TRIANGLE_HPP
#define THIRDTASK_TRIANGLE_HPP

#include <iostream>

#include "../Base/Shape.hpp"

namespace task::third {
class Triangle : public Shape {
 public:
  Triangle() = delete;

  Triangle(const Triangle &) = default;

  Triangle(Triangle &&) = default;

  Triangle &operator=(const Triangle &) = default;

  Triangle &operator=(Triangle &&) noexcept = default;

  static std::unique_ptr<Triangle> CreateUniquePtrTriangle
	  (const std::string &name, double firstSide, double secondSide, double
	  thirdSide);

  [[nodiscard]] double GetPerimeter() const override;

  [[nodiscard]] double GetSquare() const override;

  friend bool operator<(
	  const Triangle &first, const Triangle &second);

  friend bool operator>(const Triangle &first, const Triangle &second);

  friend bool operator>=(const Triangle &first, const Triangle &second);

  friend bool operator<=(const Triangle &first, const Triangle &second);

  friend bool operator==(const Triangle &first, const Triangle &second);

  friend bool operator!=(const Triangle &first, const Triangle &second);

  template<class OstreamType>
  friend std::basic_ostream<OstreamType> &operator<<(std::basic_ostream<
	  OstreamType> &out, const Triangle &triangle) {
	return out << "[" << triangle.name_ << "]:" << " " << triangle
		.GetSquare();
  }

  template<class OfstreamType>
  friend std::basic_ofstream<OfstreamType> &operator<<(std::basic_ofstream<
	  OfstreamType> &out, const Triangle &triangle) {
	return out << "[" << triangle.name_ << "]:" << " " << triangle
		.GetSquare();
  }

  template<class FstreamType>
  friend std::basic_fstream<FstreamType> &operator<<(std::basic_fstream<
	  FstreamType> &out, const Triangle &triangle) {
	return out << "[" << triangle.name_ << "]:" << " " << triangle
		.GetSquare();
  }

  ~Triangle() override = default;

 protected:

  explicit Triangle(const std::string &name, double firstSide, double
  secondSide, double thirdDouble);

  double firstSide_;
  double secondSide_;
  double thirdSide_;
};
}

#endif //THIRDTASK_TRIANGLE_HPP
