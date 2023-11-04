#include "board.hpp"
#include <cstddef>
#include <iostream>

namespace game {
    /**
     * @brief Enum showing whether current player is to be human or an AI opponent 
    */
    typedef enum _Player {Human, Computer} Player;
    std::ostream &operator << (std::ostream& os, Player player);
    
    /**
     * @brief Class managing current game
    */
    class Game {
    private:
        board::Board board;
        size_t move_count = 0;
        Player x_player = Player::Human;
        Player o_player = Player::Human;
        void move();
    public:
        void start_game();
        void set_x_player(Player);
        void set_o_player(Player);
    };
}