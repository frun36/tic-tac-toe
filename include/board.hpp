#ifndef BOARD_HPP
#define BOARD_HPP

#include <cstddef>
#include <iostream>

namespace board {
    typedef enum _FieldState {
        Empty,
        O,
        X
    } FieldState;
    std::ostream &operator << (std::ostream& os, FieldState fs);

    /**
     * @brief Takes care of basic operations on the game board
     */
    class Board {
    private:
        FieldState fields[3][3];

    public:
        Board();

        void print_board();
        void set_field(size_t i, size_t j, FieldState);
        FieldState get_field(size_t i, size_t j);
        FieldState check_rows();
        FieldState check_cols();
        FieldState check_diags();
    };
}

#endif
