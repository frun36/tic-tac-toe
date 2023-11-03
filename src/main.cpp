#include <iostream>
#include "board.hpp"
#include "game.hpp"

using namespace std;

int main(void) {
    cout << "Hellou from another device" << endl;
    board::Board board;
    board.print_board();
    board.set_field(0, 1, board::X);
    board.print_board();
    return 0;
}