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
            Board()                 = delete;
            Board(const Board&)     = default;
            Board(Board&&) noexcept = default;

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

            [[nodiscard]] value_type GetWhiteSymbol() const {
                return this->whiteSymbol_;
            }
            void SetWhiteSymbol(value_type whiteSymbol) {
                if (this->whiteSymbol_ == whiteSymbol) {
                    return;
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
                this->blackSymbol_ = blackSymbol;
            }

            template<class OstreamType>
            friend std::basic_ostream<OstreamType>& operator<<
                    (std::basic_ostream<OstreamType>& out, const Board&
                    chessBoard) {
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

            Board& operator=(const Board&) = default;

            value_type& operator[](const std::string& key) {
                return this->board_[key];
            }

            ~Board() = default;

        protected:

            explicit Board(unsigned short rows, unsigned short columns, value_type blackSymbol, value_type whiteSymbol)
                    : blackSymbol_(blackSymbol), whiteSymbol_(whiteSymbol), rowsCount_(rows), columnsCount_(columns),
                      board_() {}

            value_type whiteSymbol_;
            value_type blackSymbol_;
            unsigned short rowsCount_;
            unsigned short columnsCount_;
            std::map<std::string, value_type> board_;
        };
    }

#endif //FIRSTTASK_BOARD_HPP