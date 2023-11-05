#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include "board.hpp"

namespace computer {
class Computer {
   public:
    board::Coordinates make_move();
};
}  // namespace computer

#endif