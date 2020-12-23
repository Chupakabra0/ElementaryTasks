//
// Created by Александр Сафиюлин on 11.12.2020.
//

#pragma once

#ifndef SEVENTHTASK_MODELS_SEQUENCEBUILDER_SEQUENCEBUILDER_HPP_
#define SEVENTHTASK_MODELS_SEQUENCEBUILDER_SEQUENCEBUILDER_HPP_

#include <vector>

#include <Sequence/SequenceRules/SequenceRules.hpp>

namespace task::eighth {

template<Number Type, class RuleGenType = AfterOne,
	class RuleValidType = AlwaysTrue>
class SequenceBuilder {
 public:
//-------------------------------- CTORS ---------------------------------------

  SequenceBuilder(Type begin, Type end,
	GenRule<Type, RuleGenType> genRule = GenRule<Type, RuleGenType>(),
	ValidRule<Type, RuleValidType> validRule = ValidRule<Type, RuleValidType>())
	    : begin_(begin), end_(end), lowLimit_(nullptr),
		  highLimit_(nullptr), genRule_(genRule), validRule_(validRule) {}

  SequenceBuilder(Type begin, Type end, Type lowLimit, Type highLimit,
	GenRule<Type, RuleGenType> genRule = GenRule<Type, RuleGenType>(),
	ValidRule<Type, RuleValidType> validRule = ValidRule<Type, RuleValidType>())
	  : begin_(begin), end_(end), lowLimit_(std::make_unique<Type>(lowLimit)),
	  highLimit_(std::make_unique<Type>(highLimit)), genRule_(genRule),
	  validRule_(validRule) {}

//----------------------------- BUILD SEQUENCE ---------------------------------

  std::vector<Type> Build() const {
    // Create vector, that will be returned
	std::vector<Type> result;

	// Iteration continues from begin to end
	for (auto i = this->begin_; i < this->end_; ++i) {
	  // Generate next element of sequence
	  auto data = this->genRule_(i);

	  // If highLimit is set and data higher than it
	  if (nullptr != this->highLimit_ && data > *this->highLimit_) {
	    // Break the loop
		break;
	  }

	  // If valid rule is true and lowLimit is set and data higher than it
	  if (this->validRule_(data) &&
	  (nullptr == this->lowLimit_  || data >= *this->lowLimit_)) {
	    // Try to push data to result vector
	    try {
			result.push_back(data);
	  	}
	    catch (std::exception&) {
	      // If smth goes wrong, break loop
		  break;
	    }
	  }
	}

	// Return result
	return result;
  }

//-------------------------------- GETTERS/SETTERS -----------------------------

  [[nodiscard]] auto GetBegin() const {
	return this->begin_;
  }

  void SetBegin(Type value) {
	if (this->begin_ == value || value > this->end_) {
	  return;
	}
	this->begin_ = value;
  }

  [[nodiscard]] auto GetEnd() const {
	return this->end_;
  }

  void SetEnd(Type value) {
	if (this->end_ == value || value < this->begin_) {
	  return;
	}
	this->end_ = value;
  }

  [[nodiscard]] auto GetLowLimit() const {
	return *this->lowLimit_;
  }

  void SetLowLimit(Type value) {
	if (*this->lowLimit_ == value || value > *this->highLimit_) {
	  return;
	}
	*this->lowLimit_ = value;
  }

  [[nodiscard]] auto GetHighLimit() const {
	return *this->highLimit_;
  }

  void SetHighLimit(Type value) {
	if (*this->highLimit_ == value || value < *this->lowLimit_) {
	  return;
	}
	*this->highLimit_ = value;
  }

 private:
//---------------------------- PRIVATE FIELDS ----------------------------------

  Type begin_;
  Type end_;

  std::unique_ptr<Type> lowLimit_;
  std::unique_ptr<Type> highLimit_;

  GenRule<Type, RuleGenType> genRule_;
  ValidRule<Type, RuleValidType> validRule_;
};

}

#endif //SEVENTHTASK_MODELS_SEQUENCEBUILDER_SEQUENCEBUILDER_HPP_
