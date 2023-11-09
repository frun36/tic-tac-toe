#include "computer.hpp"

#include <cstdlib>
#include <fstream>

#define BUFFER_SIZE 1024

using namespace board;
using namespace computer;

Computer::Computer(Symbol symbol, bool force) {
    this->symbol = symbol;
    this->move_count = symbol == Symbol::X ? 0 : 1;

    std::cout << "Hello. I'm the mightiest tic-tac-toe player you will ever face. Prepare to die. \n";
    std::cout << "I shall destroy you playing as " << this->symbol << ".\n";

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

    std::cout << "I've regenerated my database and am ready to annihilate you.\n";
}

bool computer::position_is_winning(int position, size_t move_count) {
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
        if (position_is_winning(new_position, move_count)) {
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

Coordinates Computer::make_move(board::Board board) {
    this->update_position(board);
    size_t new_field;
    
    // Take the center if available
    if(board.get_field(Coordinates(5)) == Symbol::None) {
        return Coordinates(5);
    }
    
    do {
        new_field = rand() % 9 + 1;
    } while (is_in_number(this->position, new_field));

    // Update computer knowledge and return chosen move
    this->position += new_field * pow(10, 8 - move_count);
    std::cout << "New position: " << this->position << '\n';
    this->move_count += 2;
    return Coordinates(new_field);
}

void computer::Computer::update_position(board::Board board) {
    if (this->move_count == 0) {
        return;
    }

    for (size_t field = 1; field <= 9; field++) {
        if (board.get_field(Coordinates(field)) != Symbol::None && !is_in_number(this->position, field)) {
            std::cout << "Previous position: " << this->position << '\n';
            this->position += field * pow(10, 8 - move_count + 1);
            std::cout << "Current position: " << this->position << '\n';
            return;
        }
    }

    std::cerr << "Error: couldn't update position\n";
}
