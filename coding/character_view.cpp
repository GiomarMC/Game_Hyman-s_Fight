#include "character_view.h"

Character_view::Character_view(const std::string &archivo, float x, float y) : player(sf::Vector2f(100.0f, 150.0f)), posX(x), posY(y), sprite(&playerTexture, sf::Vector2u(5, 6), 0.3f)
{
    deltaTime = 0.0f;
    player = sf::RectangleShape(sf::Vector2f(100.0f, 150.0f));
    playerTexture.loadFromFile(archivo);
    player.setTexture(&playerTexture);
}

void Character_view::setPosition(float x, float y)
{
    posX = x;
    posY = y;
    player.setPosition(posX, posY);
    player.setScale(100.0f, 100.0f);
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
}