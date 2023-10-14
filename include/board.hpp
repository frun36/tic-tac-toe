#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>

typedef enum _FieldState {EMPTY, O, X} FieldState;

class Board {
    private:
        FieldState fields[3][3];
    
    public:
        Board();

        void print_board();
        void set_field(size_t, size_t, FieldState);
};

#endif