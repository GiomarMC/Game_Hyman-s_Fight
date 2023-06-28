#include "character_1.h"

character_1::character_1()
{
    name = "Hyman";
    life = 3;
    movX = 200;
    movY = 200;
    base_attack = 8;
    Skill = 15;
    this -> powerup = nullptr;
}

void character_1::special_skill()
{
    std::cout << "Realizando ataque especial";
}

void character_1::basic_attack()
{
    std::cout << "Realizando ataque basico";
}

int character_1::getX() const
{
    return movX;
}

int character_1::getY() const
{
    return movY;
}

void character_1::mov(int x)
{
    motion(x);
}

void character_1::setpowerUp(PowerUp* powerup)
{
    setpowerUp(powerup);
}