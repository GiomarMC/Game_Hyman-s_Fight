#ifndef AVATAR_H
#define AVATAR_H
#include "character.h"
#include <string>

class avatar:public character
{
    private:
        std::string name;
        int basic_attack;
        int special_skill;
        avatar();
        void motion();
        void special_skill();
        void basic_attack();
};

#endif