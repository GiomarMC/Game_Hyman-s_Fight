#ifndef GAME_H
#define GAME_H

#include <unordered_set>
#include "game_view_controller.h"
#include "game_model_controller.h"

class Game_controller
{
    private:
        Game_Model gameModel;
        Game_View<Character> gameview;
        std::unordered_set<sf::Keyboard::Key> pressedKeys;
        sf::Keyboard::Key ultimatecla;
        int row;
        bool is_move;
    public:
        Game_controller();
        void handleEvents();
        void drawPlataforms();
        void update(float);
        void run();
};

#endif