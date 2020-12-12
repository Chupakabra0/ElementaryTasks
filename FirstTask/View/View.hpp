//
// Created by Александр Сафиюлин on 27.11.2020.
//

#pragma once

#ifndef FIRSTTASK_VIEW_HPP
#define FIRSTTASK_VIEW_HPP

#include "../Services/Errors/ErrorHandler/ErrorHandler.hpp"

namespace task::first {
template<class Board, class Ostream>
class View {
 public:
  View() = delete;

  View(const View &) = delete;

  View(View &&) noexcept = delete;

  View &operator=(const View &) = delete;

  View &operator=(View &&) = delete;

  explicit View(Ostream &out, helpers::ErrorHandler errorHandler)
	  : chessBoard_(nullptr), out_(out), errorHandler_(errorHandler) {}

  explicit View(Ostream &out, Board chessBoard, const helpers::ErrorHandler
  errorHandler)
	  : chessBoard_(std::make_unique<Board>(chessBoard)), out_(out),
		errorHandler_(errorHandler) {}

  void OutBoard() {
	if (nullptr == this->chessBoard_) {
	  this->outError(helpers::ErrorCode::NOT_ENOUGH_ARGS);
	  return;
	}
	this->out_ << *this->chessBoard_;
  }

  [[nodiscard]] Board GetChessBoard() const {
	return *this->chessBoard_;
  }

  void SetChessBoard(Board chessBoard) {
	this->chessBoard_ = std::make_unique<Board>(chessBoard);
  }

  void OutNotEnoughArgsMessage() {
	this->outError(helpers::ErrorCode::NOT_ENOUGH_ARGS);
	this->out_ << "FirstTask.exe rowsCount columnsCount" << std::endl;
  }

  void OutParseError() {
	this->outError(helpers::ErrorCode::PARSE_FAILED);
  }

  void OutMemoryError() {
	this->outError(helpers::ErrorCode::MEMORY_OUT);
  }

  ~View() = default;

 private:
  void outError(const helpers::ErrorCode errorCode) {
	this->errorHandler_.SetErrorCode(errorCode);
	this->errorHandler_.OutError(std::string("\n"));
  }

  std::unique_ptr<Board> chessBoard_;
  Ostream &out_;
  helpers::ErrorHandler errorHandler_;
};
}

#endif //FIRSTTASK_VIEW_HPP
