//
// Created by Александр Сафиюлин on 12.12.2020.
//

#pragma once

#ifndef EIGHTHTASK_MODELS_FIBONACCICREATOR_FIBONACCIBUILDER_HPP_
#define EIGHTHTASK_MODELS_FIBONACCICREATOR_FIBONACCIBUILDER_HPP_

#include <vector>

namespace task::eighth {
template<class Type1, class Type2 = Type1>
class FibonacciBuilder {
 public:
  FibonacciBuilder() = delete;

  FibonacciBuilder(const FibonacciBuilder &) = default;

  FibonacciBuilder(FibonacciBuilder &&) noexcept = default;

  FibonacciBuilder &operator=(const FibonacciBuilder &) = default;

  FibonacciBuilder &operator=(FibonacciBuilder &&) noexcept = default;

  explicit FibonacciBuilder(Type1 begin, Type2 end)
	  : begin_(begin), end_(end) {}

  std::vector<Type1> Build() const {
	std::vector<Type1> vector;

	auto number = Type1();
	++number;
	auto temp = Type1();

	while (number <= static_cast<Type1>(this->end_)) {
	  if (number >= this->begin_) {
		vector.push_back(number);
	  }
	  number = number + temp;
	  temp = number - temp;
	}

	return vector;
  }

  ~FibonacciBuilder() = default;
 private:
  Type1 begin_;
  Type2 end_;
};
}

#endif //EIGHTHTASK_MODELS_FIBONACCICREATOR_FIBONACCICREATOR_HPP_