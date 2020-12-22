//
// Created by Александр Сафиюлин on 11.12.2020.
//

#pragma once

#ifndef SEVENTHTASK_MODELS_SEQUENCEBUILDER_SEQUENCEBUILDER_HPP_
#define SEVENTHTASK_MODELS_SEQUENCEBUILDER_SEQUENCEBUILDER_HPP_

#include <vector>
#include <Sequence/SequenceRules/SequenceRules.hpp>

namespace task::seventh {

template<class Type, class RuleGenType = AfterOne,
	class RuleValidType = AlwaysTrue, class RuleBreakType = AlwaysFalse>
class SequenceBuilder {
 public:
  explicit SequenceBuilder(Type begin, Type end,
	GenRule<Type, RuleGenType> genRule = GenRule<Type, RuleGenType>(),
	ValidRule<Type, RuleValidType> validRule = ValidRule<Type, RuleValidType>(),
	ValidRule<Type, RuleBreakType> breakRule = ValidRule<Type, RuleBreakType>())
	  : begin_(begin), end_(end), genRule_(genRule), validRule_(validRule),
		breakRule_(breakRule) {}

  std::vector<Type> Build() const {
	std::vector<Type> result;

	auto data = this->begin_;
	for (auto i = this->begin_; i < this->end_; ++i) {
	  if (this->breakRule_(i)) {
		break;
	  }

	  data = this->genRule_(i);

	  if (this->validRule_(data)) {
	    try {
			result.push_back(data);
	  	}
	    catch (std::exception&) {
		  return result;
	    }
	  }
	}

	return result;
  }

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

 private:
  Type begin_;
  Type end_;
  GenRule<Type, RuleGenType> genRule_;
  ValidRule<Type, RuleValidType> validRule_;
  ValidRule<Type, RuleBreakType> breakRule_;
};

}

#endif //SEVENTHTASK_MODELS_SEQUENCEBUILDER_SEQUENCEBUILDER_HPP_
