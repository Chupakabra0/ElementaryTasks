//
// Created by Александр Сафиюлин on 21.12.2020.
//

#pragma once

#ifndef SEVENTHTASK_MODELS_SEQUENCERULES_SEQUENCERULES_HPP_
#define SEVENTHTASK_MODELS_SEQUENCERULES_SEQUENCERULES_HPP_

namespace task::eighth {

template<class Type>
concept IsNumber = std::is_arithmetic_v<Type> && !(
	std::is_same_v<Type, char> || std::is_same_v<Type, unsigned char> ||
	std::is_same_v<Type, signed char> || std::is_same_v<Type, wchar_t> ||
	std::is_same_v<Type, char8_t> || std::is_same_v<Type, char16_t> ||
	std::is_same_v<Type, char32_t> || std::is_same_v<Type, bool>
);

template<IsNumber Type, class RuleType>
struct GenRule {};

struct AfterOne {};
struct AfterTwo {};
struct Fibo {};
struct AfterSqr {};

template<class Type>
struct GenRule<Type, AfterOne> {
  Type operator()(Type data) const {
	return data + static_cast<Type>(1);
  }
};

template<class Type>
struct GenRule<Type, AfterTwo> {
  Type operator()(Type data) const {
	return data + static_cast<Type>(2);
  }
};

template<class Type>
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

template<class Type>
struct GenRule<Type, AfterSqr> {
  Type operator()(Type data) const {
	return std::pow(data, static_cast<Type>(2));
  }
};

//----------------------------------------------------------------------------

template<class Type, class RuleType>
struct ValidRule {};

struct AlwaysTrue {};
struct AlwaysFalse {};
struct IsOdd {};
struct IsEven {};

template<class Type>
struct ValidRule<Type, AlwaysTrue> {
  bool operator()(Type) const {
	return true;
  }
};

template<class Type>
struct ValidRule<Type, AlwaysFalse> {
  bool operator()(Type) const {
	return false;
  }
};

template<class Type>
struct ValidRule<Type, IsOdd> {
  bool operator()(Type data) const {
	return static_cast<Type>(1) == data % static_cast<Type>(2);
  }
};

template<class Type>
struct ValidRule<Type, IsEven> {
  bool operator()(Type data) const {
	return static_cast<Type>(0) == data % static_cast<Type>(2);
  }
};
}

#endif //SEVENTHTASK_MODELS_SEQUENCERULES_SEQUENCERULES_HPP_
