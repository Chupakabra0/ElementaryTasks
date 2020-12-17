//
// Created by Александр Сафиюлин on 24.11.2020.
//

#pragma once

#ifndef FIRSTTASK_BOARD_HPP
#define FIRSTTASK_BOARD_HPP

#include <iostream>
#include <map>

namespace task::first {
template<class SymbolType>
class Board {
 public:
  using value_type = SymbolType;

  Board() = delete;

  Board(const Board &) = default;

  Board(Board &&) noexcept = default;

  Board &operator=(const Board &) = default;

  Board &operator=(Board &&) = default;

  explicit Board(
	  const unsigned short rows, const unsigned short columns,
	  value_type blackSymbol, value_type whiteSymbol)
	  : whiteSymbol_(whiteSymbol), blackSymbol_(blackSymbol),
		rowsCount_(rows), columnsCount_(columns),
		board_() {}

  [[nodiscard]] unsigned short GetRowsCount() const {
	return this->rowsCount_;
  }

  [[nodiscard]] unsigned short GetColumnsCount() const {
	return this->columnsCount_;
  }

  [[nodiscard]] value_type GetWhiteSymbol() const {
	return this->whiteSymbol_;
  }

  void SetWhiteSymbol(value_type whiteSymbol) {
	if (this->whiteSymbol_ == whiteSymbol) {
	  return;
	}

	for (auto i = 0u; i < this->board_.size(); ++i) {
		const std::string letter(1u,
			static_cast<char>('A' + i / this->columnsCount_));

		const std::string number(1u, static_cast<char>
			('0' + 1 + i % this->columnsCount_));

		if (this->board_[letter + number] == this->whiteSymbol_) {
			this->board_[letter + number] = whiteSymbol;
		}
	}

	this->whiteSymbol_ = whiteSymbol;
  }

  [[nodiscard]] value_type GetBlackSymbol() const {
	return this->blackSymbol_;
  }

  void SetBlackSymbol(value_type blackSymbol) {
	if (this->blackSymbol_ == blackSymbol) {
	  return;
	}
  	
  	for (auto i = 0u; i < this->board_.size(); ++i) {
		const std::string letter(1u,
			static_cast<char>('A' + i / this->columnsCount_));

		const std::string number(1u, static_cast<char>
			('0' + 1 + i % this->columnsCount_));
  		
  		if (this->board_[letter + number] == this->blackSymbol_) {
			this->board_[letter + number] = blackSymbol;
  		}
  	}

	this->blackSymbol_ = blackSymbol;
  }

  [[nodiscard]] std::map<std::string, value_type> GetMap() const {
	return this->board_;
  }

  void Insert(value_type symbol) {
	const std::string letter(1u,
		static_cast<char>('A' + this->board_.size() /this->columnsCount_));

	const std::string number(1u, static_cast<char>
		('0' + 1 + this->board_.size() % this->columnsCount_));

	typename std::map<std::string, value_type>::value_type element(letter + number, symbol);
	if (this->board_.size() >= this->columnsCount_ * this->rowsCount_ ||
		symbol != this->blackSymbol_ && symbol != this->whiteSymbol_) {
	  return;
	}

    try {
	  this->board_.insert(element);
	}
	catch (const std::exception &) {
	  std::cerr << "Memory error" << std::endl;
	}

  }

  template<class OstreamType>
  friend std::basic_ostream<OstreamType> &operator<<
	  (std::basic_ostream<OstreamType> &out, const Board &chessBoard) {
	auto i = 0u;
	for (const auto &element : chessBoard.board_) {
	  out << element.second;
	  if (++i >= chessBoard.columnsCount_) {
		out << '\n';
		i = 0u;
	  }
	}
	return out;
  }

  template<class OfstreamType>
  friend std::basic_ofstream<OfstreamType> &operator<<
	  (std::basic_ofstream<OfstreamType> &out, const Board &chessBoard) {
	auto i = 0u;
	for (const auto &element : chessBoard.board_) {
	  out << element.second;
	  if (++i >= chessBoard.columnsCount_) {
		out << '\n';
		i = 0u;
	  }
	}
	return out;
  }

  template<class FstreamType>
  friend std::basic_fstream<FstreamType> &operator<<
	  (std::basic_fstream<FstreamType> &out, const Board &chessBoard) {
	auto i = 0u;
	for (const auto &element : chessBoard.board_) {
	  out << element.second;
	  if (++i >= chessBoard.columnsCount_) {
		out << '\n';
		i = 0u;
	  }
	}
	return out;
  }

  value_type &operator[](const std::string &key) {
	return this->board_[key];
  }

  ~Board() = default;

 private:
  value_type whiteSymbol_;
  value_type blackSymbol_;
  unsigned short rowsCount_;
  unsigned short columnsCount_;
  std::map<std::string, value_type> board_;
};
}

#endif //FIRSTTASK_BOARD_HPP