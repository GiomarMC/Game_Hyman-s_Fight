#include "personaje.h"

Personaje::Personaje(const std::string& archivo, float x, float y) : sprite(archivo, x, y), posX(x), posY(y)
{
    
}

void Personaje::setPosition(float x, float y)
{
    posX = x;
    posY = y;
    sprite.setPosition(posX, posY);
    sprite.setScale(0.15f,0.15f);
}

void Personaje::draw(sf::RenderWindow& window)
{
    sprite.draw(window);
}