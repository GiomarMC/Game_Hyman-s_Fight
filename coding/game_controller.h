#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "character_model.h"
#include "character_view.h"
#include "Character_attributes.h"

class Game_controller
{
    private:
        sf::RenderWindow window;
        Character character;
        Character_attributes character_attributes;
        Character_view character_view;
        sf::Clock clock;
    public:
        Game_controller();
        void run();
};

#endif