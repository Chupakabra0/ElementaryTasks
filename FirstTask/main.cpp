#include <iostream>

#include "ChessBoard.hpp"

int main(int argc, char* argv[]) {
    try {
        int rows, columns;
        if (argc >= 3) {
            rows = atoi(argv[1]);
            columns = atoi(argv[2]);
        }
        else {
            std::cout << "Enter count of rows and columns:" << std::endl;
            std::cin >> rows;
            std::cin >> columns;
        }

        if (!std::cin) {
            throw std::exception("Bad input...");
        }
        if (rows < 0 || columns < 0) {
            throw std::exception("Rows or columns can't be lesser than 0...");
        }

        task::ChessBoard chessBoard(rows, columns);
        std::cout << chessBoard << std::endl;
    }
    catch (std::exception exception) {
        std::cerr << exception.what() << std::endl;
        return 1;
    }
    return 0;
}