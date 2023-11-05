#include "computer.hpp"

#include <cstdlib>

using namespace board;
using namespace computer;

Coordinates Computer::make_move() {
    size_t i = rand() % 3;
    size_t j = rand() % 3;
    return board::Coordinates(i, j);
}
