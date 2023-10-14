#include <iostream>
#include "board.hpp"

int main(void) {
    std::cout << "Hellou" << std::endl;
    Board board;
    board.print_board();
    board.set_field(0, 1, X);
    board.print_board();
    return 0;
}