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
        bool isJumping;
        bool isFalling;
        int jumpCounter;
        int jumpHeight;
        int initialY;
        float jumpSpeed;
    public:
        Character();
        void setName(const std::string&);
        void setBaseAttack(int);
        void setSpecialSkill(int);
        void setLife(int);
        void setX(int);
        void setY(int);
        void setInitialY(int);
        int getX() const;
        int getY() const;
        int getInitialY() const;
        void motion(int);
        void special_skill();
        void basic_attack();
        void jump();
        void update(float);
        void setpowerUp(PowerUp*);
        ~Character();
};

#endif