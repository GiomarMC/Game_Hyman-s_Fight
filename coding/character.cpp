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

void character::motion(int x, int y)
{
    movX += x;
    movY += y;
}

void character::special_skill(){}

void character::basic_attack(){}

void character::setpowerUp(PowerUp* poweup)
{
    this -> powerup = powerup;
    powerup -> aplicarPowerUp();
}

character::~character()
{
    delete powerup;
}