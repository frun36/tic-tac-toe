#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>

class Board {
    private:
        unsigned char fields[3][3];
    
    public:
        Board();

        void print_board();
};

#endif