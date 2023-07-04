#include "character_model.h"
#include <windows.h>
#include <iostream>

Character::Character():name(""),base_attack(0),Special_Skill(0),life(0),movX(0),movY(0),isJumping(false),
isFalling(false),powerup(NULL),jumpCounter(0),jumpHeight(100),initialY(0), jumpSpeed(5.0f)
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

void Character::setInitialY(int posY)
{
    initialY = posY;
}

int Character::getX() const
{
    return movX;
}

int Character::getY() const
{
    return movY;
}

int Character::getInitialY() const
{
    return initialY;
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

void Character::jump()
{
    if(!isJumping)
    {
        isJumping = true;
        initialY = movY;
    }
}

void Character::update(float deltatime)
{
    if(isJumping)
    {
        if(jumpCounter < jumpHeight)    
        {
            float jumpDistance = jumpSpeed * deltatime;
            movY -= jumpDistance;
            jumpCounter += jumpDistance;
        }
        else if(movY < initialY)
        {
            float fallDistance = jumpSpeed * deltatime;
            movY += fallDistance;
        }
        else
        {
            isJumping = false;
            jumpCounter = 0;
            movY = initialY;
        }
    }
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