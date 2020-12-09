//
// Created by Александр Сафиюлин on 25.11.2020.
//

#pragma once

#ifndef FIRSTTASK_VIEWMODEL_HPP
#define FIRSTTASK_VIEWMODEL_HPP

#include <iostream>

#include "../Models/Board/Board.hpp"

namespace task::first
{
	template<class BoardSymbolType>
	class ViewModel
	{
	public:
		ViewModel() = default;

		ViewModel(const ViewModel&) = default;

		ViewModel(ViewModel&&) noexcept = default;

		ViewModel& operator=(const ViewModel&) = delete;

		ViewModel& operator=(ViewModel&&) = delete;

		explicit ViewModel(const Board<BoardSymbolType>& chessBoard)
				: chessBoard_(chessBoard)
		{}

		[[nodiscard]] Board<BoardSymbolType> GetChessBoard() const
		{
			return this->chessBoard_;
		}

		void SetChessBoard(const Board<BoardSymbolType>& chessBoard)
		{
			this->chessBoard_ = chessBoard;
		}

		~ViewModel() = default;

	private:
		// TIP: maybe unique_ptr...
		Board <BoardSymbolType> chessBoard_;
	};
}

#endif //FIRSTTASK_TASK_H
