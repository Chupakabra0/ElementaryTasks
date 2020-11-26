//
// Created by Александр Сафиюлин on 25.11.2020.
//

#ifndef FIRSTTASK_VIEW_HPP
#define FIRSTTASK_VIEW_HPP

#include <ostream>

#include "ChessBoard.hpp"

namespace task::first {
        class View {
        public:
            View()  = delete;
            ~View() = default;

            explicit View(const Board& chessBoard) : chessBoard_(chessBoard) {

            }

            void Out() const {
                std::cout << this->chessBoard_ << std::endl;
            }

        private:
            Board chessBoard_;
        };
    }

#endif //FIRSTTASK_TASK_H
