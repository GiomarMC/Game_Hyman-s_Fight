#ifndef CHARACTER_1_H
#define CHARACTER_1_H

#include "character.h"

class character_1:public character
{
    public:
        character_1();
        void special_skill();
        void basic_attack();
        int getX() const;
        int getY() const;
        void mov(int);
        void setpowerUp(PowerUp*);
};

#endif