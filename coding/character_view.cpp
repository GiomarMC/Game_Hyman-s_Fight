#include "character_view.h"

Character_view::Character_view(const std::string& archivo, float x, float y) : sprite(archivo, x, y), posX(x), posY(y)
{
    
}

void Character_view::setPosition(float x, float y)
{
    posX = x;
    posY = y;
    sprite.setPosition(posX, posY);
    sprite.setScale(0.15f,0.15f);
}

void Character_view::draw(sf::RenderWindow& window)
{
    sprite.draw(window);
}