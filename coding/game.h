#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "character.h"
#include "character_view.h"

class Game
{
    private:
        sf::RenderWindow window;
        character character;
        Character_view Character_view;

    public:
        Game();
        void run();
};

#endif