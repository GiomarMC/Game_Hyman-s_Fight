#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <SFML/Graphics.hpp>
#include "sprite.h"

class Character_view
{
    private:
        Sprite sprite;
        float posX, posY;

    public:
        Character_view(const std::string& archivo, float x, float y);
        void setPosition(float x, float y);
        void draw(sf::RenderWindow& window);
};

#endif