#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <cmath>
#include <memory>
#include <chrono>
#include "Powerup.h"

class Character
{
    protected:
        std::shared_ptr<PowerUp> powerup;
        std::string name;
        int life, base_attack, Special_Skill;
        float posX, posY;
        //float velocityY;
        float groundLevel;
        float initialPosY;
        float currentPosY;
        float time;
        static const float jumpHeight;
        static const float gravity;
        bool isJumping;

        std::chrono::steady_clock::time_point powerupStarTime;

    public:
        Character();
        void setName(const std::string&);
        void setBaseAttack(int);
        void setSpecialSkill(int);
        void setLife(int);
        void setX(float);
        void setY(float);
        void setPosInitialY(float);
        void setGroundLevel(float);
        float getX() const;
        float getY() const;
        int getInitialY() const;
        void motion(float,float);
        virtual void special_skill();
        virtual void basic_attack();
        void jump();
        void update(float);
        void setpowerUp(std::unique_ptr<PowerUp>);
        void checkPowerUpDuration();
        ~Character();
};

#endif