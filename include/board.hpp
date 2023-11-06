#ifndef BOARD_HPP
#define BOARD_HPP

#include <cstddef>
#include <iostream>

namespace board {
enum Symbol {
    X,
    O,
    None,
};
std::ostream& operator<<(std::ostream& os, Symbol fs);

struct Coordinates {
    size_t i;
    size_t j;

    Coordinates(size_t i, size_t j) : i(i), j(j) {};
    Coordinates(size_t field_nr) : i((field_nr - 1) / 3), j((field_nr - 1) % 3) {};
};

/**
 * @brief Takes care of basic operations on the game board
 */
class Board {
   private:
    Symbol fields[3][3] = {{Symbol::None, Symbol::None, Symbol::None},
                           {Symbol::None, Symbol::None, Symbol::None},
                           {Symbol::None, Symbol::None, Symbol::None}};

   public:
    void print_board();
    void set_field(Coordinates coordinates, Symbol);
    Symbol get_field(Coordinates coordinates);
    Symbol check_rows();
    Symbol check_cols();
    Symbol check_diags();
};
}  // namespace board

#endif
