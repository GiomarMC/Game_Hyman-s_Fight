#include "game_controller.h"

Game_controller::Game_controller() : gameModel(), gameview()
{
    gameModel.initializeCharacter();
}

void Game_controller::handleEvents()
{
    sf::Event event;
    while (gameview.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            gameview.close();
        }
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
            gameview.close();
        }
        else if(event.type == sf::Event::KeyPressed)
        {
            pressedKeys.insert(event.key.code);
        }
        else if(event.type == sf::Event::KeyReleased)
        {
            pressedKeys.erase(event.key.code);
        }
        
    }
}

void Game_controller::update(float deltatime)
{
    auto characterptr = gameModel.getCharacter();
    if(pressedKeys.count(sf::Keyboard::Left) > 0)
        characterptr -> motion(-2,0);
    if(pressedKeys.count(sf::Keyboard::Right) > 0)
        characterptr -> motion(2,0);
    if(pressedKeys.count(sf::Keyboard::Space) > 0)
    {
        characterptr -> setPosInitialY(characterptr -> getY());
        characterptr -> jump();
    }
    gameModel.updateCharacter(deltatime);
}

void Game_controller::run()
{
    gameview.setMenuActive(true);
    gameview.FrameLimit();
    while (gameview.IsOpen())
    {
        handleEvents();
        float deltatime = gameview.getDeltatime();

        if (gameview.getMenuActive())
        {
            Menu menu(gameview.getWindow());
            int option = menu.mostrar();
            if (option == 1)
            {
                std::cout << "\nIniciando el juego\n";
                gameview.setMenuActive(false);
            }
            else if (option == 2)
            {
                std::cout << "\nConfiguracion del juego\n";
            }
            else if (option == 3)
            {
                std::cout << "\nSaliendo del juego\n";
                break;
            }
        }
        else
        {
            update(deltatime);
            gameview.clear();
            gameview.drawCharacter(*gameModel.getCharacter());
            gameview.display();
        }
    }
}