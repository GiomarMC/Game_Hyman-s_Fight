#include "game_controller.h"

Game_controller::Game_controller() : gameModel(), gameview(), is_move(true)
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
            pressedKeys.erase(event.key.code);
            if (ultimatecla == sf::Keyboard::Right)
                row = 0;
            else 
                row = 1;
            is_move = false;
        }
    }
}

void Game_controller::drawPlataforms()
{
    for(const auto plataforma: gameModel.getMapaModel().getPlataformas())
    {
        gameview.drawPlataform(plataforma.getPosX(),plataforma.getPosY(),plataforma.getWidth(),plataforma.getHeight());
    }
}

void Game_controller::update(float deltatime)
{
    auto characterptr = gameModel.getCharacter();
    auto plataformas = gameModel.getMapaModel().getPlataformas();
    bool characterOnPlataform = false;
    if(characterptr -> getX() >= plataformas[0].getPosX() && characterptr -> getX() + 30 <= plataformas[0].getPosX() + plataformas[0].getWidth())
    {
        characterptr -> setY(plataformas[0].getPosY() - 40);
        characterptr -> update(deltatime, plataformas[0].getPosY() - 60);
        characterOnPlataform = true;
    }
    if(characterptr -> getX() >= plataformas[1].getPosX() && characterptr -> getX() + 30 <= plataformas[1].getPosX() + plataformas[1].getWidth())
    {
        characterptr -> setY(plataformas[1].getPosY() - 40);
        characterptr -> update(deltatime, plataformas[1].getPosY() - 60);
        characterOnPlataform = true;
    }
    if(characterptr -> getX() >= plataformas[2].getPosX() && characterptr -> getX() + 30 <= plataformas[2].getPosX() + plataformas[2].getWidth())
    {
        characterptr -> setY(plataformas[2].getPosY() - 40);
        characterptr -> update(deltatime, plataformas[2].getPosY() - 60);
        characterOnPlataform = true;
    }
    if(!characterOnPlataform)
    {
        characterptr -> update(deltatime, 1000);
    }
    //gameModel.updateCharacter(deltatime,400);
    if(pressedKeys.count(sf::Keyboard::Left) > 0)
    {
        characterptr -> motion(-2,0);
        ultimatecla = sf::Keyboard::Right;
        row = 2;
    }
        
    if(pressedKeys.count(sf::Keyboard::Right) > 0)
    {
        characterptr -> motion(2,0);
        ultimatecla = sf::Keyboard::Left;
        row = 3;
    }
        
    if(pressedKeys.count(sf::Keyboard::Up) > 0)
    {
        characterptr -> jump();
        if (ultimatecla == sf::Keyboard::Right)
            row = 4;
        else
            row = 4;
    }
    if(pressedKeys.count(sf::Keyboard::Down) > 0) //PELEA
    {
        //characterptr -> fight();
        if (ultimatecla == sf::Keyboard::Right)
            row = 1; //6
        else 
            row = 0; //7
    }
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
            gameModel.crearPlataformas();
            update(deltatime);
            gameview.clear();
            gameview.drawCharacter(*gameModel.getCharacter(), row, is_move, deltatime);
            drawPlataforms();
            gameview.display();
        }
    }
}