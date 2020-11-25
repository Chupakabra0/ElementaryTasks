//
// Created by Александр Сафиюлин on 24.11.2020.
//

#ifndef FIRSTTASK_CHESSBOARD_HPP
#define FIRSTTASK_CHESSBOARD_HPP

#include <ostream>

namespace task {
    class ChessBoard {
    public:
        ChessBoard()                  = delete;
        ChessBoard(const ChessBoard&) = default;
        ChessBoard(ChessBoard&&)      = default;

        ChessBoard(unsigned rowsAndColumns) : ChessBoard(rowsAndColumns, rowsAndColumns) {}

        ChessBoard(unsigned rows, unsigned columns) : rows_(rows), columns_(columns) {}

        [[nodiscard]] unsigned GetRows() const {
            return this->rows_;
        }
        void SetRows(unsigned rows) {
            if (this->rows_ == rows) {
                return;
            }
            this->rows_ = rows;
        }

        [[nodiscard]] unsigned GetColumns() const {
            return this->columns_;
        }
        void SetColumns(unsigned columns) {
            if (this->columns_ == columns) {
                return;
            }
            this->columns_ = columns;
        }

        template<class Type>
        friend std::basic_ostream<Type> &operator<<(std::basic_ostream<Type>& out, const ChessBoard& chessBoard) {
            if (chessBoard.rows_ == 0 || chessBoard.columns_ == 0) {
                return out;
            }

            auto outStarOrBlink = [](std::basic_ostream<Type>& out, unsigned first, unsigned second, auto predicate) -> std::basic_ostream<Type>& {
                if (predicate(first, second)) {
                    return out << '*';
                }
                return out << ' ';
            };

            for (auto i = 0u; i < chessBoard.rows_; ++i) {
                for (auto j = 0u; j < chessBoard.columns_; ++j) {
                    if (i % 2 == 0) {
                        outStarOrBlink(out, j % 2, 0u,  std::equal_to<>());
                    }
                    else {
                        outStarOrBlink(out, j % 2, 0u, std::not_equal_to<>());
                    }
                }
                out << '\n';
            }
            return out;
        }

        ~ChessBoard() = default;

    private:
        unsigned rows_;
        unsigned columns_;
    };
}

#endif //FIRSTTASK_CHESSBOARD_HPP