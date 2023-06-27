#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "character.h"

class Player
{
    private:
        std::string name;
        std::vector<character*> characters;
    public:
        Player(const std::string&);
        std::string getName() const;
        void selectCharacter(character*);
        std::vector<character*> getCharacters() const;
};

#endif