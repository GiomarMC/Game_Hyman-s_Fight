#include "character_model.h"

const float Character::jumpHeight = 120.0f;
const float Character::gravity = 9.8f;

Character::Character():name(""),base_attack(0),Special_Skill(0),life(0),posX(0.0f),posY(0.0f), /*velocityY(0),*/ isJumping(true), groundLevel(0), initialPosY(0.0f), currentPosY(0.0f), time(0.0f),
powerupStarTime(std::chrono::steady_clock::now())
{

}

void Character::setName(const std::string& newName) {name = newName;}

void Character::setBaseAttack(int newBaseAttack) {base_attack = newBaseAttack;}

void Character::setSpecialSkill(int newSpecialSkill) {Special_Skill = newSpecialSkill;}

void Character::setLife(int newLife) {life = newLife;}

void Character::setX(float newX) {posX = newX;}

void Character::setY(float newY) {posY = newY;}

void Character::setPosInitialY(float Y) {initialPosY = Y;}

void Character::setGroundLevel(float groundlevel) {groundLevel = groundlevel;}

float Character::getX() const {return posX;}

float Character::getY() const {return posY;}

int Character::getInitialY() const {return initialPosY;}

void Character::motion(float x, float y)
{
    posX += x;
    posY += y;
}

void Character::special_skill() {}

void Character::basic_attack() {}

void Character::jump()
{
    if(!isJumping)
    {
        isJumping = true;
        initialPosY = static_cast<float>(posY);
        currentPosY = initialPosY;
        time = 0.0f;
    }
}

void Character::update(float deltatime)
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

        posY = static_cast<int>(currentPosY);
    }
    else
    {
        int prevPosy = posY;
        posY += static_cast<int>(gravity*deltatime);

        if(posY <= groundLevel)
        {
            posY = groundLevel;
            if(prevPosy > groundLevel)
            {
                isJumping = false;
                currentPosY = static_cast<float>(posY);
            }
        }
    }
}


void Character::setpowerUp(std::unique_ptr<PowerUp> Newpowerup)
{
    powerup = std::move(Newpowerup);
    powerup -> aplicarPowerUp();

    powerupStarTime = std::chrono::steady_clock::now(); 
}

void Character::checkPowerUpDuration()
{
    if (powerup)
    {
        auto currentTime = std::chrono::steady_clock::now();
        auto durationInSeconds = std::chrono::duration_cast<std::chrono::seconds>(currentTime - powerupStarTime).count();

        if (durationInSeconds >= 8)
            powerup.reset();
    }
}

Character::~Character()
{
    
}