#include "player.h"

Player::Player(const std::string& name):name(name)
{
    
}

std::string Player::getName() const
{
    return name;
}

void Player::selectCharacter(character* character)
{

}

std::vector<character*> Player::getCharacters() const
{
    return characters;
}