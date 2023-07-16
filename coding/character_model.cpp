#include "character_model.h"
#include <windows.h>
#include <iostream>

const float Character::jumpHeight = 100.0f;
const float Character::gravity = 9.8f;

Character::Character():name(""),base_attack(0),Special_Skill(0),life(0),movX(0),movY(0),powerup(NULL),isJumping(false), initialPosY(0.0f), currentPosY(0.0f), time(0.0f)
{

}

void Character::setName(const std::string& newName) {name = newName;}

void Character::setBaseAttack(int newBaseAttack) {base_attack = newBaseAttack;}

void Character::setSpecialSkill(int newSpecialSkill) {Special_Skill = newSpecialSkill;}

void Character::setLife(int newLife) {life = newLife;}

void Character::setX(int newX) {movX = newX;}

void Character::setY(int newY) {movY = newY;}

void Character::setPosInitialY(int Y) {initialPosY = Y;}

int Character::getX() const {return movX;}

int Character::getY() const {return movY;}

int Character::getInitialY() const {return initialPosY;}

void Character::motion(float x, float y)
{
    movX += x;
    movY += y;
}

void Character::special_skill() {}

void Character::basic_attack() {}

void Character::jump()
{
    if(!isJumping)
    {
        isJumping = true;
        initialPosY = static_cast<float>(movY);
        currentPosY = initialPosY;
        time = 0.0f;
    }
}

void Character::update(float deltatime,int groundLevel)
{
    if(isJumping)
    {
        float jumpDuration = 2.0f * sqrtf(jumpHeight/gravity);
        time += deltatime;
        if(time <= jumpDuration)
            currentPosY = initialPosY - gravity * time * (jumpDuration - time);
        else
        {
            isJumping = false;
            currentPosY = initialPosY;
        }

        movY = static_cast<int>(currentPosY);
    }
    else
    {
        int prevPosy = movY;
        movY += static_cast<int>(gravity*deltatime);

        if(movY <= groundLevel)
        {
            movY = groundLevel;
            if(prevPosy > groundLevel)
            {
                isJumping = false;
                currentPosY = static_cast<float>(movY);
            }
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