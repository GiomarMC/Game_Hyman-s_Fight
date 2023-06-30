#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "character_view.h"
#include "character_1.h"
class Game
{
    private:
        sf::RenderWindow window;
        character_1 character;
        Character_view Character_view;
    

    public:
        Game();
        void run();
};

#endif