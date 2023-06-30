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
void Character_view::moveCharacterLeft() {
    sprite.indiceX = 2;
    if (sprite.indiceY>=0 && sprite.indiceY<= 5)
        sprite.indiceY++;
    else
        sprite.indiceY=0;
    ultimatecla = sf::Keyboard::Left;
}

void Character_view::moveCharacterRight() {
    sprite.indiceX = 1;
    if (sprite.indiceY>=0 && sprite.indiceY<= 5)
        sprite.indiceY++;
    else
        sprite.indiceY=0;
    ultimatecla = sf::Keyboard::Right;
}