#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "character.h"
#include "character_view.h"
#include "Character_attributes.h"

class Game
{
    private:
        sf::RenderWindow window;
        Character character;
        Character_attributes character_attributes;
        Character_view character_view;
    public:
        Game();
        void run();
};

#endif