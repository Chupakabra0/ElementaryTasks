//
// Created by Александр Сафиюлин on 11.12.2020.
//

#pragma once

#ifndef SEVENTHTASK_MODELS_SEQUENCEBUILDER_SEQUENCEBUILDER_HPP_
#define SEVENTHTASK_MODELS_SEQUENCEBUILDER_SEQUENCEBUILDER_HPP_

#include <vector>

namespace task::seventh {

template<class Type1, class Type2 = Type1>
class SequenceBuilder {
 public:
  SequenceBuilder() = delete;

  SequenceBuilder(const SequenceBuilder &) = default;

  SequenceBuilder(SequenceBuilder &&) noexcept = default;

  SequenceBuilder &operator=(const SequenceBuilder &) = default;

  SequenceBuilder &operator=(SequenceBuilder &&) noexcept = default;

  explicit SequenceBuilder(Type1 begin, Type2 end)
	  : begin_(begin), end_(end) {}

  std::vector<Type1> Build() const {
	Type1 number;
	std::vector<Type1> vector;

	for (auto i = this->begin_; i < static_cast<Type1>(this->end_); ++i) {
	  vector.push_back(i);
	}

	return vector;
  }

  ~SequenceBuilder() = default;
 private:
  Type1 begin_;
  Type2 end_;
};
}

#endif //SEVENTHTASK_MODELS_SEQUENCEBUILDER_SEQUENCEBUILDER_HPP_
