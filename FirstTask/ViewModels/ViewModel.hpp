//
// Created by Александр Сафиюлин on 25.11.2020.
//

#ifndef FIRSTTASK_VIEWMODEL_HPP
#define FIRSTTASK_VIEWMODEL_HPP

#include <iostream>

#include "../Models/Board/Board.hpp"

namespace task::first {
        class ViewModel {
        public:
            ViewModel()                  = default;
            ViewModel(const ViewModel&)  = default;
            ViewModel(ViewModel&&)       = default;

            explicit ViewModel(const Board& chessBoard) : chessBoard_(chessBoard) {}

            [[nodiscard]] Board GetChessBoard() const {
                return this->chessBoard_;
            }
            void SetChessBoard(const Board& chessBoard) {
                this->chessBoard_ = chessBoard;
            }

            ~ViewModel() = default;
        private:
            Board chessBoard_;
        };
    }

#endif //FIRSTTASK_TASK_H
