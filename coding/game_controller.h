#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "character.h"
#include "character_view.h"
#include "character_attributes.h"
#include "model_controller.h"

class Game
{
    private:
        sf::RenderWindow window;
        Character character;
        Character_view Character_view;
        Character_attributes character_attributes;
    public:
        Game();
        void run();
};

#endif