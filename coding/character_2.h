#ifndef CHARACTER_2_H
#define CHARACTER_2_H

#include "character.h"

class character_2:public character
{
    public:
        character_2();
        void special_skill();
        void basic_attack();
        int getX() const;
        int getY() const;
        void mov(int);
        void setpowerUp(PowerUp*);
};

#endif