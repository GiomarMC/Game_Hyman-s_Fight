#include "character.h"
#include <windows.h>
#include <iostream>

character::character()
{
    life = 100;
    name = "Player";
    movX = 0;
    movY = 0;
    this -> powerup = nullptr;
}

void character::mov(int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_INPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void character::special_skill()
{
    std::cout << "Ejecutando habilidad especial";
}

void character::basic_attack()
{
    std::cout << "Ejecutando ataque basico";
}

void character::setpowerUp(PowerUp* poweup)
{
    this -> powerup = powerup;
    powerup -> aplicarPowerUp();
}

character::~character()
{
    delete[] powerup;
}