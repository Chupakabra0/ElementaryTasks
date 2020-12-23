//
// Created by Александр Сафиюлин on 21.12.2020.
//

#pragma once

#ifndef SEVENTHTASK_MODELS_SEQUENCERULES_SEQUENCERULES_HPP_
#define SEVENTHTASK_MODELS_SEQUENCERULES_SEQUENCERULES_HPP_

namespace task::eighth {

// Concept, that controls Type is arithmetic number type
template<class Type>
concept Number = std::is_arithmetic_v<Type> && !(
	std::is_same_v<Type, char> || std::is_same_v<Type, unsigned char> ||
	std::is_same_v<Type, signed char> || std::is_same_v<Type, wchar_t> ||
	std::is_same_v<Type, char8_t> || std::is_same_v<Type, char16_t> ||
	std::is_same_v<Type, char32_t> || std::is_same_v<Type, bool>
);

// It controls generation rules
// Class-functor, that have to be specialized
template<Number Type, class RuleType>
struct GenRule {};

// By these dummies
struct AfterOne {};
struct AfterTwo {};
struct Fibo {};
struct Sqr {};

// Specialization for step-by-step iteration
template<Number Type>
struct GenRule<Type, AfterOne> {
  Type operator()(Type data) const {
	return data;
  }
};

// Specialization for "in two" iteration
template<Number Type>
struct GenRule<Type, AfterTwo> {
  Type operator()(Type data) const {
	return data * 2;
  }
};

// Specialization for "Fibonacci" iteration
template<Number Type>
struct GenRule<Type, Fibo> {
  Type operator()(Type number) const {
	if (static_cast<Type>(0) == number || static_cast<Type>(1) == number) {
	  return number;
	}

	auto result = 1u;
	auto temp = 0u;

	for (auto i = 1u; i < number; ++i) {
	  result = result + temp;
	  temp = result - temp;
	}

	return result;
  }
};

// Specialization for "Fibonacci" iteration
template<Number Type>
struct GenRule<Type, Sqr> {
  Type operator()(Type data) const {
	return static_cast<Type>(std::pow(data, static_cast<Type>(2)));
  }
};

//----------------------------------------------------------------------------

// It controls validation of sequence's elements
// Class-functor, that have to be specialized
template<Number Type, class RuleType>
struct ValidRule {};

// By these dummies
struct AlwaysTrue {};
struct AlwaysFalse {};
struct IsOdd {};
struct IsEven {};

// Specialization for always true valid
template<Number Type>
struct ValidRule<Type, AlwaysTrue> {
  bool operator()(Type) const {
	return true;
  }
};

// Specialization for always false valid
template<Number Type>
struct ValidRule<Type, AlwaysFalse> {
  bool operator()(Type) const {
	return false;
  }
};

// Specialization for always odd valid
template<Number Type>
struct ValidRule<Type, IsOdd> {
  bool operator()(Type data) const {
	return static_cast<Type>(1) == data % static_cast<Type>(2);
  }
};

// Specialization for always even valid
template<Number Type>
struct ValidRule<Type, IsEven> {
  bool operator()(Type data) const {
	return static_cast<Type>(0) == data % static_cast<Type>(2);
  }
};
}

#endif //SEVENTHTASK_MODELS_SEQUENCERULES_SEQUENCERULES_HPP_
