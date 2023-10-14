#include "board.hpp"

Board::Board() {
    for (size_t x = 0; x < 3; x++)
        for (size_t y = 0; y < 3; y++)
            this->fields[x][y] = 0;
}

void Board::print_board() {
    for (size_t x = 0; x < 3; x++) {
        for (size_t y = 0; y < 3; y++) {
            switch (this->fields[x][y]) {
                case 0:
                    std::cout << "-";
                    break;
                case 1:
                    std::cout << "O";
                    break;
                case 2:
                    std::cout << "X";
                    break;
                default:
                    return;
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}