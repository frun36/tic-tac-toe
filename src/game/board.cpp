#include "board.hpp"

Board::Board() {
    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            this->fields[i][j] = EMPTY;
    std::cout << "Initialized new empty board" << std::endl;
}

/**
 * @brief Sets specified field in desired `FieldState`
 * 
 * @param i - row index [0-2]
 * @param j - column index [0-2]
 * @param state - desired `FieldState`
*/
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

FieldState Board::check_rows() {
    FieldState winner;
    for (size_t i = 0; i < 3; i++) {
        winner = this->fields[i][0];
        if (winner != EMPTY && winner == this->fields[i][1] && winner == this->fields[i][2]) {
            return winner;
        }
    }
    return EMPTY;
}

FieldState Board::check_cols() {
    FieldState winner;
    for (size_t j = 0; j < 3; j++) {
        winner = this->fields[0][j];
        if (winner != EMPTY && winner == this->fields[1][j] && winner == this->fields[2][j]) {
            return winner;
        }
    }
    return EMPTY;
}

FieldState Board::check_diags() {
    FieldState winner = this->fields[1][1];
    if (winner != EMPTY && ((winner == this->fields[0][0] && winner == this->fields[2][2]) || (winner == this->fields[0][2] && winner == this->fields[2][0]))) {
        return winner;
    }
    return EMPTY;
}