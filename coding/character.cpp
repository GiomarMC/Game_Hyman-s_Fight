#include "character.h"
#include <windows.h>
#include <iostream>

Character::Character():name(""),base_attack(0),Special_Skill(0),life(0),movX(0),movY(0),isFalling(false),powerup(NULL)
{

}

Character::Character(std::string _name,int _base_attack,int _special_skill,int _life,int _movX, int _movY):name(_name),base_attack(_base_attack),
Special_Skill(_special_skill),life(_life),movX(_movX),movY(_movY),isFalling(false),powerup(NULL)
{
    
}

void Character::setName(const std::string& newName)
{
    name = newName;
}

void Character::setBaseAttack(int newBaseAttack)
{
    base_attack = newBaseAttack;
}

void Character::setSpecialSkill(int newSpecialSkill)
{
    Special_Skill = newSpecialSkill;
}

void Character::setLife(int newLife)
{
    life = newLife;
}

void Character::setX(int newX)
{
    movX = newX;
}

void Character::setY(int newY)
{
    movY = newY;
}

int Character::getX() const
{
    return movX;
}

int Character::getY() const
{
    return movY;
}

void Character::motion(int x)
{
    movX += x;
}

void Character::special_skill()
{

}

void Character::basic_attack()
{

}

void Character::setpowerUp(PowerUp* poweup)
{
    this -> powerup = powerup;
    powerup -> aplicarPowerUp();
}

Character::~Character()
{
    if (powerup != nullptr) {
        delete powerup;
    }
}