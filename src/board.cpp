#include "board.hpp"

Board::Board() {
    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            this->fields[i][j] = EMPTY;
}

void Board::set_field(size_t i, size_t j, FieldState state) {
    this->fields[i][j] = state;
}

void Board::print_board() {
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            switch (this->fields[i][j]) {
                case EMPTY:
                    std::cout << "-";
                    break;
                case O:
                    std::cout << "O";
                    break;
                case X:
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