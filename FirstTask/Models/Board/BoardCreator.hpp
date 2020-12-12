//
// Created by Александр Сафиюлин on 26.11.2020.
//

#pragma once

#ifndef FIRSTTASK_BOARDCREATOR_HPP
#define FIRSTTASK_BOARDCREATOR_HPP

#include "Board.hpp"

namespace task::first {
template<class SymbolType>
class BoardCreator {
 public:
  using value_type = SymbolType;

  BoardCreator() = delete;

  BoardCreator(const BoardCreator &) = default;

  BoardCreator(BoardCreator &&) noexcept = default;

  BoardCreator &operator=(const BoardCreator &) = delete;

  BoardCreator &operator=(BoardCreator &&) = delete;

  BoardCreator(value_type blackSymbol, value_type whiteSymbol)
	  : whiteSymbol_(whiteSymbol), blackSymbol_(blackSymbol) {}

  std::unique_ptr<Board<value_type>> CreateBoard
	  (unsigned short rowsCount, unsigned short columnsCount) {
	if (0 == rowsCount || 0 == columnsCount) {
	  return nullptr;
	}

	std::unique_ptr<task::first::Board<value_type>> result
		(new(std::nothrow)
			 Board(rowsCount, columnsCount, this->blackSymbol_,
				   this->whiteSymbol_));
	if (nullptr == result) {
	  return nullptr;
	}

	for (auto i = static_cast<unsigned short>(0); i < rowsCount; ++i) {
	  for (auto j = static_cast<unsigned short>(0); j <
		  columnsCount; ++j) {
		value_type symbol;
		if (i % 2 == 0) {
		  symbol = this->outStarOrBlink(j % 2, 0u,
										std::equal_to<>());
		} else {
		  symbol = this->outStarOrBlink(j % 2, 0u,
										std::not_equal_to<>());
		}
		result->Insert(std::map<std::string, value_type>::value_type
						   (getKey(std::string(1u, 'A' + i),
								   std::string(1u,
											   j + 1 + '0')),
							symbol));
	  }
	}

	return result;
  }

  ~BoardCreator() = default;

 protected:
  static std::string getKey
	  (const std::string &letter, const std::string &number) {
	return letter + number;
  }

  template<class Predicate>
  value_type outStarOrBlink(
	  unsigned short first, unsigned short second,
	  Predicate predicate) {
	if (predicate(first, second)) {
	  return this->blackSymbol_;
	}
	return this->whiteSymbol_;
  }

  value_type whiteSymbol_;
  value_type blackSymbol_;
};
}

#endif //FIRSTTASK_BOARDCREATOR_HPP