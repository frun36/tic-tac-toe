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
            size_t move_count;
            Player x_player;
            Player o_player;
            void move();
        public:
            Game(Player, Player);
            void start_game();
    };
}