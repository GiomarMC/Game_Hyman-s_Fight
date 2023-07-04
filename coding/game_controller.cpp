#include "game_controller.h"

Game_controller::Game_controller() : window(sf::VideoMode(800, 600), "Hyman's Fight"), character(),character_attributes(), character_view("E:\\Game_final_CC2\\character.png", 400, 300)
{
    character.setName(character_attributes.getCharacter_name(3));
    character.setBaseAttack(character_attributes.getCharacter_base_attack(3));
    character.setSpecialSkill(character_attributes.getCharacter_special_skill(3));
    character.setLife(character_attributes.getlife());
    character.setX(300);
    character.setY(300);
}

void Game_controller::run() 
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
                        character.motion(-2);
                        character_view.moveCharacterLeft();
                        break;
                    case sf::Keyboard::Right:
                        character.motion(2);
                        character_view.moveCharacterRight();
                        break;
                    case sf::Keyboard::Space:
                        character.setInitialY(200);
                        character.jump();
                        break;
                    default:
                        break;
                }
            }
        }
        float deltatime = clock.restart().asSeconds();
        character.update(deltatime);
        // Actualizar lógica del juego en el modelo
        // ...

        // Limpiar la ventana
        window.clear();

        // Dibujar el personaje en el view
        character_view.setPosition(character.getX(), character.getY());
        character_view.draw(window);

        // Mostrar la ventana
        window.display();
    }
}