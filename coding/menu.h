#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Menu {
public:
    Menu(sf::RenderWindow&);
    int mostrar();

private:
    sf::RenderWindow& window;
    sf::Font font;
    sf::RectangleShape inicioButton;
    sf::RectangleShape configuracionButton;
    sf::RectangleShape salirButton;
    std::vector<sf::Text> buttonsText;
    sf::Texture fondoTexture;
    sf::Sprite fondoSprite;

    void configurarBoton(sf::RectangleShape&, const std::string&, float);
    void dibujarBoton(const sf::RectangleShape&);
    void dibujarTexto();
    
};

#endif