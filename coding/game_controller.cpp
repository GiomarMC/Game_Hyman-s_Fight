#include "game_controller.h"

Game_controller::Game_controller() : gameModel(), gameview()
{
    gameModel.initializeCharacter();
}

void Game_controller::drawPlataforms()
{
    for(const auto plataforma: gameModel.getMapaModel().getPlataformas())
    {
        gameview.drawPlataform(plataforma -> getPosX(),plataforma -> getPosY(),plataforma -> getWidth(),plataforma -> getHeight());
    }
}

void Game_controller::update(float deltatime)
{
    auto characterptr = gameModel.getCharacter();
    auto plataformas = gameModel.getMapaModel().getPlataformas();
    bool characterOnPlataform = true;
    if(characterptr -> getX() >= plataformas[0] -> getPosX() && characterptr -> getX() + 30 <= plataformas[0] -> getPosX() + plataformas[0] -> getWidth())
    {
        characterptr -> setGroundLevel(plataformas[0] -> getPosY() - 30);
        characterOnPlataform = true;
    }
    if(characterptr -> getX() >= plataformas[1] -> getPosX() && characterptr -> getX() + 30 <= plataformas[1] -> getPosX() + plataformas[1] -> getWidth())
    {
        characterptr -> setGroundLevel(plataformas[1] -> getPosY() - 30);
        characterOnPlataform = true;
    }
    if(characterptr -> getX() >= plataformas[2] -> getPosX() && characterptr -> getX() + 30 <= plataformas[2] -> getPosX() + plataformas[2] -> getWidth())
    {
        characterptr -> setGroundLevel(plataformas[2] -> getPosY() - 30);
        characterOnPlataform = true;
    }
    if(!characterOnPlataform)
    {
        characterptr -> setGroundLevel(1000);
    }
    gameview.update();
    if(gameview.getIs_Left() || gameview.getIs_Right())
    {
        characterptr -> motion(gameview.getPosX(),gameview.getPosY());
    }
    if(gameview.isJumping())
    {
        characterptr -> jump();
    }
    characterptr -> update(deltatime);
}

void Game_controller::run()
{
    gameview.setMenuActive(true);
    gameview.FrameLimit();
    Menu menu_view;
    while (gameview.IsOpen())
    {
        gameview.handleEvents();
        float deltatime = gameview.getDeltatime();

        if (gameview.getMenuActive())
        {
            menu_view.mostrar();
            gameModel.RunMenu(menu_view.getMouseX(), menu_view.getMouseY());
            if(gameModel.getIs_Finally())
            {
                menu_view.setIsMenuActive(false);
                gameview.setMenuActive(false);
            }
        }
        else
        {
            gameModel.crearPlataformas();
            update(deltatime);
            gameview.clear();
            gameview.drawCharacter(*gameModel.getCharacter());
            drawPlataforms();
            gameview.display();
        }
    }
}