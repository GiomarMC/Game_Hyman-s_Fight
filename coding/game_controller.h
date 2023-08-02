#ifndef GAME_H
#define GAME_H

#include "game_view_controller.h"
#include "game_model_controller.h"

class Game_controller
{
    private:
        Game_Model gameModel;
        Game_View<Character> gameview;
    public:
        Game_controller();
        void drawPlataforms();
        void update(float);
        void run();
};

#endif