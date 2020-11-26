//
// Created by Александр Сафиюлин on 24.11.2020.
//

#ifndef FIRSTTASK_BOARD_HPP
#define FIRSTTASK_BOARD_HPP

#include <ostream>
#include <map>
#include <cstring>

namespace task::first {
        class Board {
            // TIP: VERY VERY doubtful thing...
            friend class BoardFactory;
            using value_type = char;
        public:
            Board()                        = delete;
            Board(const Board &)           = default;
            Board(Board &&) noexcept       = default;
            Board& operator=(const Board&) = delete;
            Board& operator=(Board&&)      = delete;

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
                for (const auto& element : chessBoard.board_) {
                    out << element.second;
                    if (++i >= chessBoard.columnsCount_) {
                        out << '\n';
                        i = 0u;
                    }
                }
                return out;
            }

            value_type& operator[](const std::string& key) {
                return this->board_[key];
            }

            ~Board() = default;

        protected:

            explicit Board(unsigned short rows, unsigned short columns, value_type blackSymbol, value_type whiteSymbol)
                    : blackSymbol_(blackSymbol), whiteSymbol_(whiteSymbol), rowsCount_(rows), columnsCount_(columns),
                      board_() {}

            [[maybe_unused]] value_type whiteSymbol_;
            [[maybe_unused]] value_type blackSymbol_;
            unsigned short rowsCount_;
            unsigned short columnsCount_;
            std::map<std::string, value_type> board_;
        };
    }

#endif //FIRSTTASK_BOARD_HPP