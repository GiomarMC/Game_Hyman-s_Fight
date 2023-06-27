#include "game.h"
#include "menu.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Menu del Juego");
    Menu menu(window);
    menu.ejecutar();
    return 0;
}