#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include "character.h"

int main()
{
    character personaje;
    int x = 10, y = 10;
    personaje.mov(x,y);
    std::cout << "*";
    bool game_over = false;
    char tecla;
    while(!game_over)
    {
        if(kbhit())
        {
            tecla = getch();
            personaje.mov(x,y);
            std::cout << " ";

            if(tecla == 'w')
                y--;
            if(tecla == 's')
                y++;
            if(tecla == 'd')
                x++;
            if(tecla == 'a')
                x--;
            personaje.mov(x,y);
            std::cout << "*";
        }
        if (tecla == 'q')
        {
            game_over = true;
        }
    }
    return 0;
}