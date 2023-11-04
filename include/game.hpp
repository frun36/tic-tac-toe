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
    std::tuple<size_t, size_t> player_move();
    std::tuple<size_t, size_t> computer_move();
    bool verify_move(std::tuple<size_t, size_t>);
    board::Symbol check_board();

   public:
    board::Symbol play();
    void set_x_player_mode(PlayerMode);
    void set_o_player_mode(PlayerMode);
};
}  // namespace game