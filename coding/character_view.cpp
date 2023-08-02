#include "character_view.h"

Character_view::Character_view(const std::string &archivo) : sprite(archivo)
{
    sprite.setScale(1.5f,1.5f);
    //ARRAY DE CANTIDAD DE SPRITES POR FILA
    character_sprite = {8,8,8,8,4};    
}

void Character_view::setPosition(float x, float y)
{
    posX = x;
    posY = y;
    sprite.setPosition(posX, posY);
}

void Character_view::draw(sf::RenderWindow& window)
{
    sprite.draw(window);
}

//DIBUJA EL SPRITE DEPENDIENTE DE LAS TECLAS PRESIONADAS
void Character_view::printCharacter(int numPos)
{ 
    int x = character_sprite[numPos];
    sprite.setMove(numPos, x);
    sprite.setScale(0.5f,0.5f);
}

//DIBUJA EL SPRITE INDEPENDIENTE
void Character_view::moveCharacterNone(int numPos, float deltaTime)
{
    int x = character_sprite[numPos];
    sprite.setNoMove(numPos, x, deltaTime);
}