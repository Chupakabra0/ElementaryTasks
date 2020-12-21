//
// Created by Александр Сафиюлин on 21.12.2020.
//

#pragma once

#ifndef FOURTHTASK_MODELS_FILEPARSERLINEBYLINE_DATAFUNCTIONS_HPP_
#define FOURTHTASK_MODELS_FILEPARSERLINEBYLINE_DATAFUNCTIONS_HPP_

namespace task::fourth {
class DataFunctions {
 public:
  DataFunctions() = delete;

  DataFunctions(const DataFunctions&) = delete;

  DataFunctions(DataFunctions&&) = delete;

  DataFunctions& operator=(const DataFunctions&) = delete;

  DataFunctions& operator=(DataFunctions&&) = delete;

  template<class Iter, class Type>
  static unsigned CountEq(Iter begin, Iter end, Type value) {
    auto result = 0u;
    for (auto i = begin; i != end; ++i) {
      if (*i == value) {
        ++result;
      }
    }

	return result;
  }

  template<class Iter, class Type>
  static void ReplaceEq(Iter begin, Iter end, Type value, Type replace) {
	for (auto& i = begin; i != end; ++i) {
	  if (*i == value) {
		*i = replace;
	  }
	}
  }
};
}

#endif //FOURTHTASK_MODELS_FILEPARSERLINEBYLINE_DATAFUNCTIONS_HPP_
