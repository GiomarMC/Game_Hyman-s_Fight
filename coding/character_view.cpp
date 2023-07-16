#include "character_view.h"

Character_view::Character_view(const std::string& archivo) : sprite(archivo), posX(0), posY(0)
{
    
}

void Character_view::setPosition(float x, float y)
{
    posX = x;
    posY = y;
    sprite.setPosition(posX, posY);
    sprite.setScale(0.15f,0.15f);
}

void Character_view::draw(sf::RenderWindow& window)
{
    sprite.draw(window);
}
void Character_view::moveCharacterLeft() {
    sprite.indiceX = 2;
    if (sprite.indiceY>=0 && sprite.indiceY<= 5)
        sprite.indiceY++;
    else
        sprite.indiceY=0;
    ultimatecla = sf::Keyboard::Left;
}

void Character_view::moveCharacterRight() {
    sprite.indiceX = 1;
    if (sprite.indiceY>=0 && sprite.indiceY<= 5)
        sprite.indiceY++;
    else
        sprite.indiceY=0;
    ultimatecla = sf::Keyboard::Right;
}

/*Character_view::Character_view(const std::string &archivo) : player(sf::Vector2f(100.0f, 150.0f)), sprite(&playerTexture, sf::Vector2u(5, 6), 0.3f)
{
    deltaTime = 0.0f;
    playerTexture.loadFromFile(archivo);
    player.setTexture(&playerTexture);
}

void Character_view::setPosition(float x, float y)
{
    posX = x;
    posY = y;
    player.setPosition(posX, posY);
    player.setScale(0.5f, 0.5f);
}

void Character_view::draw(sf::RenderWindow &window)
{
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
        
        sprite.Update(0, deltaTime, false);

        player.setTextureRect(sprite.uvRect);

        
        window.clear(sf::Color::Cyan);

        
        window.draw(player);

        // Mostrar la ventana
        window.display();
    }
}*/