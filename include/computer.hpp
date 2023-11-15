#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include "board.hpp"

namespace computer {
class Computer {
   public:
    Computer(board::Symbol symbol, bool force = false);
    board::Coordinates make_move(const board::Board& board);

   private:
    int position = 0;
    const board::Symbol symbol;
    size_t move_count = 0;
    void update_position(const board::Board& board);

    static void generate_tree(std::ofstream&, int, size_t);
    static int nth_digit(int num, int n);
    static bool is_in_number(int num, int digit);
    static int pow(int base, unsigned int exponent);
    static bool position_is_winning(int position, size_t move_count);
};
}  // namespace computer

#endif