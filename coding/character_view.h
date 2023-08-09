#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "sprite.h"

class Character_view
{
    private:
        float posX, posY;
        Sprite sprite;
        std::vector<int>character_sprite;

    public:
        Character_view(const std::string&);
        void setPosition(float, float);
        void draw(sf::RenderWindow&);
        void printCharacter(int);
        void moveCharacterNone(int,float);
};

#endif