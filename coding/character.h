#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
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
        bool isFalling;
    public:
        Character();
        Character(std::string,int,int,int,int,int);
        void setName(const std::string& newName);
        void setBaseAttack(int newBaseAttack);
        void setSpecialSkill(int newSpecialSkill);
        void setLife(int newLife);
        void setX(int newX);
        void setY(int newY);
        int getX() const;
        int getY() const;
        void motion(int);
        void special_skill();
        void basic_attack();
        void setpowerUp(PowerUp*);
        ~Character();
};

#endif