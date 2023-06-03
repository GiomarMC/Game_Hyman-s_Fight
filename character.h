#ifndef CHARACTER_H
#define CHARACTER_H

class character
{
    private:
        int life;
        character();
        void motion();
        virtual void special_skill(){};
        virtual void basic_attack(){};
};

#endif