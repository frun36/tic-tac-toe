#include "computer.hpp"

#include <cstdlib>
#include <fstream>

using namespace board;
using namespace computer;

Computer::Computer(bool force) {
    const char *fname = "game_tree";
    if (!force) {
        std::ifstream f(fname);
        if (f.good()) {
            f.close();
            return;
        }
    }

    std::ofstream f(fname);
    generate_tree(f, 0, 0);
    f.close();
}

bool computer::entry_is_winning(int position, size_t move_count) {
    if (move_count < 4) {
        return false;
    }
    Board board;
    Symbol curr_symbol = move_count % 2 == 0 ? Symbol::X : Symbol::O;
    for (size_t i = move_count % 2; i <= move_count; i += 2) {
        board.set_field(Coordinates(nth_digit(position, 8 - i)), curr_symbol);
    }
    return board.check_cols() == curr_symbol || board.check_rows() == curr_symbol || board.check_diags() == curr_symbol;
}

int computer::pow(int base, unsigned int exponent) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 0) {
            exponent /= 2;
            base *= base;
        } else {
            exponent -= 1;
            result *= base;
        }
    }

    return result;
}

int computer::nth_digit(int num, int n) {
    return (num / pow(10, n)) % 10;
}

bool computer::is_in_number(int num, int digit) {
    for (size_t i = 0; i < 9; i++) {
        if (digit == nth_digit(num, i)) {
            return true;
        }
    }
    return false;
}

void computer::generate_tree(std::ofstream &f, int position, size_t move_count) {
    if (move_count >= 9) {
        return;
    }
    for (size_t i = 1; i <= 9; i++) {
        if (is_in_number(position, i)) {
            continue;
        }
        int new_position = position + i * pow(10, 8 - move_count);
        f << new_position;
        if (entry_is_winning(new_position, move_count)) {
            f << (move_count % 2 == 0 ? "X\n" : "O\n");
            return;
        } else if (move_count >= 8) {
            f << "D\n";
            return;
        } else {
            f << "?\n";
        }

        generate_tree(f, new_position, move_count + 1);
    }
}

Coordinates Computer::make_move() {
    std::cout << "Hahaha I'm the greatest player in the world\n";
    size_t i = rand() % 3;
    size_t j = rand() % 3;
    return board::Coordinates(i, j);
}
