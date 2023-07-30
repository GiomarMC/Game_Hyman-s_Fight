#include "character_model.h"

const float Character::jumpHeight = 100.0f;
const float Character::gravity = 9.8f;

Character::Character():name(""),base_attack(0),Special_Skill(0),life(0),posX(0),posY(0),isJumping(false), VelocityY(0.0f), jumpSpeed(0.0f), initialPosY(0.0f), currentPosY(0.0f), time(0.0f), plataformPosX(0), plataformPosY(0),
powerupStarTime(std::chrono::steady_clock::now())
{

}

void Character::setName(const std::string& newName) {name = newName;}

void Character::setBaseAttack(int newBaseAttack) {base_attack = newBaseAttack;}

void Character::setSpecialSkill(int newSpecialSkill) {Special_Skill = newSpecialSkill;}

void Character::setLife(int newLife) {life = newLife;}

void Character::setX(int newX) {posX = newX;}

void Character::setY(int newY) {posY = newY;}

void Character::setPosInitialY(int Y) {initialPosY = Y;}

void Character::setPlataformPosX(float POSX) {plataformPosX = POSX;}

void Character::setPlataformPosY(float POSY) {plataformPosY = POSY;}

int Character::getX() const {return posX;}

int Character::getY() const {return posY;}

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
        float jumpDuration = 2.0f * sqrtf(jumpHeight/gravity);
        jumpSpeed = gravity * jumpDuration;
        VelocityY = -sqrtf(2.0f * gravity * jumpSpeed);
    }
}

void Character::update(float deltatime,int groundLevel)
{
    if(isJumping)
    {
        VelocityY += gravity * deltatime;
        posY += static_cast<int>(VelocityY * deltatime);
        if (posY >= groundLevel) {
            posY = groundLevel;
            isJumping = false;
            VelocityY = 0.0f;
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