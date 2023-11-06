#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include "board.hpp"

void generate_tree(std::ofstream&, int, size_t);

namespace computer {
class Computer {
   public:
    Computer(bool force);
    board::Coordinates make_move();
};
}  // namespace computer

#endif