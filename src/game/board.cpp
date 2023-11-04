#include "board.hpp"
#include <iostream>

using namespace board;
using namespace std;

std::ostream &board::operator << (std::ostream& os, FieldState fs) {
    switch(fs) {
        case FieldState::Empty:
            os << "-";
            break;
        case FieldState::O:
            os << "O";
            break;
        case FieldState::X:
            os << "X";
            break;
        default:
            os << "?";
    }
    return os;
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

FieldState Board::get_field(size_t i, size_t j) {
    return this->fields[i][j];
}

void Board::print_board() {
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            cout << this->fields[i][j] << " ";
        }
        cout << endl;
    }
}

FieldState Board::check_rows() {
    FieldState winner;
    for (size_t i = 0; i < 3; i++) {
        winner = this->fields[i][0];
        if (winner != FieldState::Empty && winner == this->fields[i][1] && winner == this->fields[i][2]) {
            return winner;
        }
    }
    return FieldState::Empty;
}

FieldState Board::check_cols() {
    FieldState winner;
    for (size_t j = 0; j < 3; j++) {
        winner = this->fields[0][j];
        if (winner != FieldState::Empty && winner == this->fields[1][j] && winner == this->fields[2][j]) {
            return winner;
        }
    }
    return FieldState::Empty;
}

FieldState Board::check_diags() {
    FieldState winner = this->fields[1][1];
    if (winner != FieldState::Empty && ((winner == this->fields[0][0] && winner == this->fields[2][2]) || (winner == this->fields[0][2] && winner == this->fields[2][0]))) {
        return winner;
    }
    return FieldState::Empty;
}
