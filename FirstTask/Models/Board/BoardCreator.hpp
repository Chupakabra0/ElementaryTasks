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

  BoardCreator &operator=(const BoardCreator &) = default;

  BoardCreator &operator=(BoardCreator &&) = default;

  BoardCreator(value_type blackSymbol, value_type whiteSymbol)
	  : whiteSymbol_(whiteSymbol), blackSymbol_(blackSymbol) {}

  std::unique_ptr<Board<value_type>> CreateBoard
	  (unsigned short rowsCount, unsigned short columnsCount) const {
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
		result->Insert(symbol);
	  }
	}

	return result;
  }

  value_type GetWhiteSymbol() const {
	return this->whiteSymbol_;
  }
  void SetWhiteSymbol(const value_type value) {
	if (this->whiteSymbol_ == value) {
	  return;
	}
	this->whiteSymbol_ = value;
  }

  value_type GetBlackSymbol() const {
	return this->blackSymbol_;
  }
  void SetBlackSymbol(const value_type value) {
    if (this->blackSymbol_ == value) {
	  return;
    }
	this->blackSymbol_ = value;
  }

  ~BoardCreator() = default;

 protected:
  template<class Predicate>
  value_type outStarOrBlink(
	  unsigned short first, unsigned short second,
	  Predicate predicate) const {
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