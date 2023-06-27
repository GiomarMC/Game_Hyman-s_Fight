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
    public:
        character();
        int getX() const;
        int getY() const;
        void motion(int,int);
        virtual void special_skill();
        virtual void basic_attack();
        void setpowerUp(PowerUp*);
        ~character();
};

#endif