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
        std::unique_ptr<PowerUp> powerup;
        std::string name;
        int life;
        int base_attack;
        int Special_Skill;
        int movX, movY;
        float initialPosY;
        float currentPosY;
        float time;
        float jumpForce;
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
        void setX(int);
        void setY(int);
        void setPosInitialY(int);
        int getX() const;
        int getY() const;
        int getInitialY() const;
        void motion(float,float);
        virtual void special_skill();
        virtual void basic_attack();
        void jump();
        void update(float,int);
        void setpowerUp(std::unique_ptr<PowerUp>);
        void checkPowerUpDuration();
        ~Character();
};

#endif