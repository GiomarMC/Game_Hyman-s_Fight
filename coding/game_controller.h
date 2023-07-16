#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <unordered_set>
#include "game_view_controller.h"
#include "character_model.h"
#include "character_view.h"
#include "Character_attributes.h"

class Game_controller
{
    private:
        Character character;
        Character_attributes character_attributes;
        Game_View<Character> gameview;
        std::unordered_set<sf::Keyboard::Key> pressedKeys;
        bool isMovingLeft;
        bool isMovingRight;
        bool isJumping;
    public:
        Game_controller();
        void handleEvents();
        void update(float);
        void run();
};

#endif