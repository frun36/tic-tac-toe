#ifndef GAME_HPP
#define GAME_HPP

#include <cstddef>
#include <iostream>
#include <tuple>

#include "board.hpp"

namespace game {
/**
 * @brief Enum showing whether current player is to be human or an AI opponent
 */
enum PlayerMode { Human,
                  Computer };
std::ostream& operator<<(std::ostream& os, PlayerMode player);

/**
 * @brief Class managing current game
 */
class Game {
   private:
    board::Board board;
    size_t move_count = 0;
    PlayerMode x_player_mode = PlayerMode::Human;
    PlayerMode o_player_mode = PlayerMode::Human;
    board::Coordinates player_move();
    board::Coordinates computer_move();
    bool verify_move(board::Coordinates);
    board::Symbol check_board();

   public:
    board::Symbol play();
    void set_x_player_mode(PlayerMode);
    void set_o_player_mode(PlayerMode);
};
}  // namespace game

#endif