//
// Created by Александр Сафиюлин on 24.11.2020.
//

#ifndef FIRSTTASK_CHESSBOARD_HPP
#define FIRSTTASK_CHESSBOARD_HPP

#include <ostream>
#include <map>
#include <cstring>

namespace task::first {
        class Board {
            using value_type = char;
        public:
            Board()                        = delete;
            Board(const Board &)           = default;
            Board(Board &&) noexcept       = default;
            Board& operator=(const Board&) = delete;
            Board& operator=(Board&&)      = delete;

            explicit Board(unsigned short rowsAndColumns) : Board(rowsAndColumns, rowsAndColumns) {}

            Board(unsigned short rows, unsigned short columns)
                    : Board(rows, columns, value_type('*'), value_type(' ')) {}

            Board(unsigned short rows, unsigned short columns, value_type blackSymbol, value_type whiteSymbol)
                    : blackSymbol_(blackSymbol), whiteSymbol_(whiteSymbol), rowsCount_(rows), columnsCount_(columns),
                      board_() {
                if (this->rowsCount_ == 0 || this->columnsCount_ == 0) {
                    return;
                }

                auto outStarOrBlink = [this](unsigned short first, unsigned short second,
                                             auto predicate) -> value_type {
                    if (predicate(first, second)) {
                        return this->blackSymbol_;
                    }
                    return this->whiteSymbol_;
                };

                for (unsigned short i = 0u; i < this->rowsCount_; ++i) {
                    for (unsigned short j = 0u; j < this->columnsCount_; ++j) {
                        value_type temp;
                        if (i % 2 == 0) {
                            temp = outStarOrBlink(j % 2, 0u, std::equal_to<>());
                        } else {
                            temp = outStarOrBlink(j % 2, 0u, std::not_equal_to<>());
                        }
                        std::string letterIndex(1u, 'A' + i);
                        std::string numberIndex(1u, j + 1 + '0');
                        this->board_.insert(std::pair<std::string, value_type>(letterIndex + numberIndex, temp));
                    }
                }
            }

            [[nodiscard]] unsigned short GetRowsCount() const {
                return this->rowsCount_;
            }
            void SetRowsCount(unsigned short rows) {
                if (this->rowsCount_ == rows) {
                    return;
                }
                this->rowsCount_ = rows;
            }

            [[nodiscard]] unsigned short GetColumnsCount() const {
                return this->columnsCount_;
            }
            void SetColumnsCount(unsigned short columns) {
                if (this->columnsCount_ == columns) {
                    return;
                }
                this->columnsCount_ = columns;
            }

            template<class OstreamType>
            friend std::basic_ostream<OstreamType>& operator<<(std::basic_ostream<OstreamType> &out, const Board &chessBoard) {
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

            ~Board() = default;

        private:
            value_type whiteSymbol_;
            value_type blackSymbol_;
            unsigned short rowsCount_;
            unsigned short columnsCount_;
            std::map<std::string, value_type> board_;
        };
    }

#endif //FIRSTTASK_CHESSBOARD_HPP