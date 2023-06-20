#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include "Powerup.h"

class character
{
    private:
        PowerUp* powerup;
        std::string name;
        int life;
        int movX, movY;
    public:
        character();
        void mov(int,int);
        void special_skill();
        void basic_attack();
        void setpowerUp(PowerUp*);
        ~character();
};

#endif