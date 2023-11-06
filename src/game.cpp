#include "game.hpp"
#include "computer.hpp"

#include <iostream>
#include <string>

using namespace board;
using namespace game;

std::ostream& game::operator<<(std::ostream& os, PlayerMode player_mode) {
    switch (player_mode) {
        case PlayerMode::Human:
            os << "Human";
            break;
        case PlayerMode::Computer:
            os << "Computer";
            break;
        default:
            os << "?";
    }
    return os;
}

Coordinates Game::player_move() {
    std::cout << "Enter field number (1-9): ";
    size_t field_nr;
    std::cin >> field_nr;
    return Coordinates (field_nr);
}

Coordinates Game::computer_move(Symbol player) {
    ComputerCell computer_opt;
    if(player == Symbol::X) {
        computer_opt = this->x_computer;
    } else {
        computer_opt = this->o_computer;
    }
    
    if(!computer_opt.has_value()) {
        std::cerr << "Error: No computer found for current player. Making random move\n";
        size_t i = rand() % 3;
        size_t j = rand() % 3;
        return board::Coordinates(i, j);
    }
    auto computer = computer_opt.value();
    std::cout << "Calling computer to move\n";
    return computer->make_move(this->board);
}

bool Game::verify_move(Coordinates coordinates) {
    if (this->board.get_field(coordinates) != Symbol::None) {
        return false;
    } else {
        return true;
    }
}

Symbol Game::check_board() {
    Symbol cols = this->board.check_cols();
    Symbol rows = this->board.check_rows();
    Symbol diags = this->board.check_diags();
    if (cols != Symbol::None) {
        return cols;
    }
    if (rows != Symbol::None) {
        return rows;
    }
    if (diags != Symbol::None) {
        return diags;
    }
    return Symbol::None;
}

Symbol Game::play() {
    std::cout << "Game between:\nX: " << this->x_player_mode << "\nO: " << this->o_player_mode << '\n';
    for (; this->move_count < 9; this->move_count++) {
        Symbol curr_player_symbol = this->move_count % 2 == 0 ? Symbol::X : Symbol::O;
        PlayerMode curr_player_mode = curr_player_symbol == Symbol::X ? this->x_player_mode : this->o_player_mode;
        Coordinates curr_move (0, 0);

        std::cout << curr_player_symbol << "'s move\n";
        this->board.print_board();

        do {
            if (curr_player_mode == PlayerMode::Human) {
                curr_move = this->player_move();
            } else {
                curr_move = this->computer_move(curr_player_symbol);
            }
        } while (!this->verify_move(curr_move));

        this->board.set_field(curr_move, curr_player_symbol);

        Symbol winner = this->check_board();
        if (winner != Symbol::None) {
            std::cout << winner << " wins\n";
            this->board.print_board();
            return winner;
        }
    }

    std::cout << "It's a draw!\n";
    this->board.print_board();
    return Symbol::None;
}

void game::Game::set_x_player_mode(PlayerMode player_mode) {
    this->x_player_mode = player_mode;
    if(player_mode == PlayerMode::Computer) {
        this->x_computer = new computer::Computer(Symbol::X, true);
    } else {
        this->x_computer = {};
    }
}

void game::Game::set_o_player_mode(PlayerMode player_mode) {
    this->o_player_mode = player_mode;
    if(player_mode == PlayerMode::Computer) {
        this->o_computer = new computer::Computer(Symbol::O, false);
    } else {
        this->o_computer = {};
    }
}