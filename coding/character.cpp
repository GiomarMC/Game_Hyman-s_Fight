#include "character.h"
#include <windows.h>
#include <iostream>

character::character()
{
    life = 3;
    name = "Player";
    movX = 0;
    movY = 0;
    base_attack = 0;
    Skill = 0;
    isFalling = false;
    VelocityY = 0.0f;
    gravity = 1.0f;
    this -> powerup = nullptr;
}

int character::getX() const
{
    return movX;
}

int character::getY() const
{
    return movY;
}

void character::motion(int x)
{
    movX += x;
}

void character::special_skill()
{

}

void character::basic_attack()
{

}

void character::setpowerUp(PowerUp* poweup)
{
    this -> powerup = powerup;
    powerup -> aplicarPowerUp();
}

void character::applyGravity()
{
    if(isFalling)
    {
        VelocityY += gravity;
        movY += static_cast<int>(VelocityY);
    }
}

void character::jump()
{
    VelocityY = -5.0f;
    isFalling = true;
}

void character::update()
{
    applyGravity();
    if(movY >= 0)
    {
        isFalling = false;
        VelocityY = 0.0f;
        movY = 0;
    }
}

character::~character()
{
    if (powerup != nullptr) {
        delete powerup;
    }
}