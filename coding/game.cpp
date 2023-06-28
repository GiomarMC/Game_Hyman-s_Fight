#include "game.h"

Game::Game() : window(sf::VideoMode(800, 600), "Hyman's Fight"), prueba1(), Character_view("D:\\VIDEOJUEGO\\Game_Hyman-s_Fight\\character.png", 400, 300)
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
                    case sf::Keyboard::Left:
                        prueba1.char1.mov(-2);
                        Character_view.moveCharacterLeft();
                        break;
                    case sf::Keyboard::Right:
                        prueba1.char1.mov(2);
                        Character_view.moveCharacterRight();
                        break;
                    case sf::Keyboard::Space:
                        prueba1.char1.jump();
                        break;
                    default:
                        break;
                }
            }
        }
        prueba1.char1.update();

        // Actualizar lógica del juego en el modelo
        // ...

        // Limpiar la ventana
        window.clear();

        // Dibujar el personaje en el view
        Character_view.setPosition(prueba1.char1.getX(), prueba1.char1.getY());
        Character_view.draw(window);

        // Mostrar la ventana
        window.display();
    }
}