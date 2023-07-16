#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <cmath>
#include "Powerup.h"

class Character
{
    protected:
        PowerUp* powerup;
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
        void setpowerUp(PowerUp*);
        ~Character();
};

#endif