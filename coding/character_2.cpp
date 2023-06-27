#include "character_2.h"

character_2::character_2()
{
    name = "Hyman";
    life = 3;
    movX = 0;
    movY = 0;
    base_attack = 8;
    Skill = 15;
    this -> powerup = nullptr;
}

void character_2::special_skill()
{
    std::cout << "Realizando ataque especial";
}

void character_2::basic_attack()
{
    std::cout << "Realizando ataque basico";
}

int character_2::getX() const
{
    return movX;
}

int character_2::getY() const
{
    return movY;
}

void character_2::mov(int x, int y)
{
    motion(x,y);
}

void character_2::setpowerUp(PowerUp* powerup)
{
    setpowerUp(powerup);
}