#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include "Powerup.h"

class character
{
    protected:
        PowerUp* powerup;
        std::string name;
        int life;
        int base_attack;
        int Skill;
        int movX, movY;
        bool isFalling;
        float VelocityY;
        float gravity;
    public:
        character();
        int getX() const;
        int getY() const;
        void motion(int);
        virtual void special_skill();
        virtual void basic_attack();
        void setpowerUp(PowerUp*);
        void applyGravity();
        void jump();
        void update();
        ~character();
};

#endif