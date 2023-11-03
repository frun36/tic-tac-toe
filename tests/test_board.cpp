#include <iostream>
#include "board.hpp"
#include "game.hpp"

using namespace std;

int x_check(Board board) {
    return (board.check_cols() == X && board.check_rows() == X && board.check_diags() == X);
}

int o_check(Board board) {
    return (board.check_cols() == O && board.check_rows() == O && board.check_diags() == O);
}


int main() {
    Board board_x, board_o, board_alt;
    for(size_t i = 0; i < 3; i++) {
        for(size_t j = 0; j < 3; j++) {
            board_x.set_field(i, j, X);
            board_o.set_field(i, j, O);
        }
    }

    return !(x_check(board_x) | 
          !x_check(board_o) | 
          !o_check(board_x) | 
          o_check(board_o));
}