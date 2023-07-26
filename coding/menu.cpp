#include "menu.h"

Menu::Menu(sf::RenderWindow& window):window (window)
{       
    if (!font.loadFromFile("Fuentes/Alice.ttf"))
    {
        std::cout << "Error al cargar la fuente";
    }
    configurarBoton(inicioButton, "Inicio", 300.f);
    configurarBoton(configuracionButton, "Configuracion", 400.f);
    configurarBoton(salirButton, "Salir", 500.f);
    if (!fondoTexture.loadFromFile("Images/map.jpg"))
    {
        std::cout << "Error al cargar la imagen";
    }
    fondoSprite.setTexture(fondoTexture);
}

int Menu::mostrar()
{
    int state = 0;
    while(window.isOpen() && state == 0)
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
            else if(event.type == sf::Event::MouseButtonReleased)
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    {
                        if(inicioButton.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
                        {
                            std::cout << "Iniciando el juego";
                            state = 1;
                        }
                        if(configuracionButton.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
                        {
                            std::cout << "Configuracion del juego";
                            state = 2;
                        }
                        if(salirButton.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
                        {
                            std::cout << "Saliendo del juego";
                            state = 3;
                        }
                    }
                }
            }
        }
        window.clear();
        window.draw(fondoSprite);
        dibujarBoton(inicioButton);
        dibujarBoton(configuracionButton);
        dibujarBoton(salirButton);
        dibujarTexto();
        window.display();
        if(state == 1)
        {
            return state;
            break;
        }
    }
    return state;
}
void Menu::configurarBoton(sf::RectangleShape& button, const std::string& buttonText, float windowHeight)
{
    button.setSize(sf::Vector2f(200.f, 50.f));
    button.setPosition(window.getSize().x / 2.f - button.getSize().x / 2.f, windowHeight / 1.f);
    button.setFillColor(sf::Color::Yellow);

    sf::Text text;
    text.setFont(font);
    text.setString(buttonText);
    text.setCharacterSize(35);
    text.setFillColor(sf::Color::Black);
    text.setPosition(button.getPosition().x + button.getSize().x / 2.f - text.getLocalBounds().width / 2.f,
                        button.getPosition().y + button.getSize().y / 2.f - text.getLocalBounds().height / 1.f);

    buttonsText.push_back(text);
}
void Menu::dibujarBoton(const sf::RectangleShape& button)
{
    window.draw(button);
}
void Menu::dibujarTexto()
{
    sf::Text juegoText;
    juegoText.setFont(font);
    juegoText.setString("Himan's Fight");
    juegoText.setCharacterSize(70);
    juegoText.setFillColor(sf::Color::Yellow);
    juegoText.setPosition(window.getSize().x / 2.f - juegoText.getLocalBounds().width / 2.f, 200.f);
    window.draw(juegoText);
    for (const sf::Text& text : buttonsText)
    {
        window.draw(text);
    }
}