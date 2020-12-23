#pragma once

#ifndef SIXTHTASK_INTEGRAL_HPP
#define SIXTHTASK_INTEGRAL_HPP

namespace task::helpers {
// Class that unites different methods of numeric find of integral
class Integral {
 public:
//----------------------------- CTOR -------------------------------------------

  Integral(const Integral &) = delete;

  Integral(Integral &&) = delete;

  Integral& operator=(const Integral&) = delete;

  Integral& operator=(Integral&&) = delete;

  explicit Integral(const unsigned n = baseN) : n_(n) {}

//-------------------------- INTEGRAL COUNT ------------------------------------

  // Simpson's (parabola's) method
  template<class Function>
  [[nodiscard]] double SimpsonCount(Function function, const double a,
							 const double b) const {
    // Count step
	const auto h = (b - a) / this->n_;
	// From this we start our find of solution
	auto temp = h * (function(a) + function(b)) / 6.0;

	// It's not redundant code, this is NaN check for arbitrarily small numbers
	// If NaN
	if (temp != temp) {
	  // Set arbitrarily small number epsilon
	  temp = std::numeric_limits<double>::epsilon();
	}
	auto result = temp;

	// First iteration
	for (auto i = 1u; i <= this->n_; ++i) {
	  auto temp = (4.0 / 6.0) * h * function(a + h * i - h / 2.0);
	  if (temp != temp) {
		temp = std::numeric_limits<double>::epsilon();
	  }
	  result += temp;
	}

	// Second iteration
	for (auto i = 1u; i <= this->n_ - 1; ++i) {
	  auto temp = (2.0 / 6.0) * h * function(a + h * i);
	  if (temp != temp) {
		temp = std::numeric_limits<double>::epsilon();
	  }
	  result += temp;
	}

	// Return result
	return result;
  }

//------------------------- GETTERS/SETTERS ------------------------------------

  [[nodiscard]] unsigned GetN() const {
	return this->n_;
  }

  void SetN(const unsigned n) {
    if (this->n_ == n) {
	  return;
    }
	this->n_ = n;
  }

//------------------------------- DTOR -----------------------------------------

  ~Integral() = default;

 private:
//----------------------------- PRIVATE FIELDS ---------------------------------

  unsigned n_;

//---------------------------- STATIC CONSTS -----------------------------------

  static const unsigned baseN = 1000u;
};
}

#endif //SIXTHTASK_INTEGRAL_HPP
