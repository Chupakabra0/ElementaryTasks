//
// Created by Александр Сафиюлин on 26.11.2020.
//

#ifndef FIRSTTASK_BOARDFACTORY_HPP
#define FIRSTTASK_BOARDFACTORY_HPP

#include "Board.hpp"

namespace task::first {
    class BoardFactory {
        using value_type = char;
    public:
        BoardFactory()                    = delete;
        BoardFactory(const BoardFactory&) = default;
        BoardFactory(BoardFactory&&)      = default;

        BoardFactory(value_type blackSymbol, value_type whiteSymbol)
            : blackSymbol_(blackSymbol), whiteSymbol_(whiteSymbol) {}

        task::first::Board* CreateBoard(unsigned short rowsCount,
                           unsigned short columnsCount) {
            if (rowsCount == 0 || columnsCount == 0) {
                return nullptr;
            }

            // TODO nullptr check
            auto* result = new Board(rowsCount, columnsCount,
                                     this->blackSymbol_, this->whiteSymbol_);

            auto outStarOrBlink = [this](unsigned short first, unsigned short second,
                                         auto predicate) -> value_type {
                if (predicate(first, second)) {
                    return this->blackSymbol_;
                }
                return this->whiteSymbol_;
            };

            for (unsigned short i = 0u; i < rowsCount; ++i) {
                for (unsigned short j = 0u; j < columnsCount; ++j) {
                    value_type symbol;
                    if (i % 2 == 0) {
                        symbol = outStarOrBlink(j % 2, 0u, std::equal_to<>());
                    } else {
                        symbol = outStarOrBlink(j % 2, 0u, std::not_equal_to<>());
                    }
                    result->board_.insert(std::pair<std::string, value_type>
                            (getKey(std::string(1u, 'A' + i),
                                          std::string(1u, j + 1 + '0')),
                             symbol));
                }
            }

            return result;
        }

        ~BoardFactory() = default;

    protected:
        static std::string getKey(const std::string& letter, const std::string&
        number) {
            return letter + number;
        }

        value_type whiteSymbol_;
        value_type blackSymbol_;
    };
}

#endif //FIRSTTASK_BOARDFACTORY_HPP
