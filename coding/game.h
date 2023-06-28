#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
//#include "character_1.h"
#include "character_view.h"
#include "game_model.h"
class Game
{
    private:
        sf::RenderWindow window;
        //character_1 character;
        Character_view Character_view;
        Game_Model prueba1;

    public:
        Game();
        void run();
};

#endif