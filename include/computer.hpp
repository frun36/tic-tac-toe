#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include "board.hpp"

namespace computer {

void generate_tree(std::ofstream&, int, size_t);
int nth_digit(int num, int n);
bool is_in_number(int num, int digit);
int pow(int base, unsigned int exponent);
bool position_is_winning(int position, size_t move_count);

class Computer {
   public:
    Computer(board::Symbol symbol, bool force);
    board::Coordinates make_move(board::Board board);

   private:
    int position = 0;
    board::Symbol symbol;
    size_t move_count = 0;
    void update_position(board::Board board);
};
}  // namespace computer

#endif