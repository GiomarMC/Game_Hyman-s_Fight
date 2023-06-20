#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <SFML/Graphics.hpp>
#include "sprite.h"

class Personaje
{
private:
    Sprite sprite;
    float posX, posY;

public:
    Personaje(const std::string& archivo, float x, float y);
    void setPosition(float x, float y);
    void draw(sf::RenderWindow& window);
};

#endif