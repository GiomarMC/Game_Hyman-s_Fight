#include "game.h"

Game::Game() : window(sf::VideoMode(800, 600), "Hyman's Fight"), character(), Character_view("D:\\Game_CC2\\Game_Hyman-s_Fight\\character.png", 400, 300)
{
    Character_view.setPosition(400,150);
}

void Game::run()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                // Controlar eventos de teclado
                switch (event.key.code)
                {
                    case sf::Keyboard::Up:
                        character.mov(0, -2);
                        break;
                    case sf::Keyboard::Down:
                        character.mov(0, 2);
                        break;
                    case sf::Keyboard::Left:
                        character.mov(-2, 0);
                        break;
                    case sf::Keyboard::Right:
                        character.mov(2, 0);
                        break;
                    default:
                        break;
                }
            }
        }

        // Actualizar lógica del juego en el modelo
        // ...

        // Limpiar la ventana
        window.clear();

        // Dibujar el personaje en el view
        Character_view.setPosition(character.getX(), character.getY());
        Character_view.draw(window);

        // Mostrar la ventana
        window.display();
    }
}