//
// Created by Александр Сафиюлин on 08.12.2020.
//

#ifndef SIXTHTASK_INTEGRAL_HPP
#define SIXTHTASK_INTEGRAL_HPP

namespace task::helpers {
class Integral {
 public:
  Integral(const Integral &) = delete;

  Integral(Integral &&) = delete;

  Integral& operator=(const Integral&) = delete;

  Integral& operator=(Integral&&) = delete;

  explicit Integral(const unsigned n = 1000u) : n_(n) {}

  template<class Function>
  [[nodiscard]] double SimpsonCount(Function function, const double a,
							 const double b) {
	const auto h = (b - a) / this->n_;
	auto temp = h * (function(a) + function(b)) / 6.0;

	if (temp != temp) {
	  temp = std::numeric_limits<double>::epsilon();
	}
	auto result = temp;

	for (auto i = 1u; i <= this->n_; ++i) {
	  auto temp = (4.0 / 6.0) * h * function(a + h * i - h / 2.0);
	  if (temp != temp) {
		temp = std::numeric_limits<double>::epsilon();
	  }
	  result += temp;
	}

	for (auto i = 1u; i <= this->n_ - 1; ++i) {
	  auto temp = (2.0 / 6.0) * h * function(a + h * i);
	  if (temp != temp) {
		temp = std::numeric_limits<double>::epsilon();
	  }
	  result += temp;
	}

	return result;
  }

  [[nodiscard]] unsigned GetN() const {
	return this->n_;
  }

  void SetN(const unsigned n) {
    if (this->n_ == n) {
	  return;
    }
	this->n_ = n;
  }

  ~Integral() = default;
 private:
  unsigned n_;
};
}

#endif //SIXTHTASK_INTEGRAL_HPP
