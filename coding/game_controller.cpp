#include "game_controller.h"

Game_controller::Game_controller() : character(),character_attributes(), gameview()
{
    character.setName(character_attributes.getCharacter_name(3));
    character.setBaseAttack(character_attributes.getCharacter_base_attack(3));
    character.setSpecialSkill(character_attributes.getCharacter_special_skill(3));
    character.setLife(character_attributes.getlife());
    character.setX(300);
    character.setY(300);
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
    if(pressedKeys.count(sf::Keyboard::Left) > 0)
        character.motion(-2,0);
    if(pressedKeys.count(sf::Keyboard::Right) > 0)
        character.motion(2,0);
    if(pressedKeys.count(sf::Keyboard::Space) > 0)
    {
       character.setPosInitialY(character.getY());
        character.jump();
    }
    character.update(deltatime,400);
}

void Game_controller::run()
{
    gameview.FrameLimit();
    while (gameview.IsOpen())
    {
        handleEvents();
        float deltatime = gameview.getDeltatime();
        update(deltatime);
        gameview.clear();
        gameview.drawCharacter(character);
        gameview.display();
    }
}