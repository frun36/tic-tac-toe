#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include "board.hpp"

namespace computer {

void generate_tree(std::ofstream&, int, size_t);
int nth_digit(int num, int n);
bool is_in_number(int num, int digit);
int pow(int base, unsigned int exponent);
bool entry_is_winning(int position, size_t move_count);

class Computer {
   public:
    Computer(bool force);
    board::Coordinates make_move();
};
}  // namespace computer

#endif