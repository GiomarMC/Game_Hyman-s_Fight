#ifndef MENU_VIEW_H
#define MENU_VIEW_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <time.h>
#include <type_traits>
#include <cmath>
#include <memory>

class Menu
{
    private:
        bool estado = false;
        int cont = 0;
        float Ancho, Alto;
        float posX, posY;
        std::shared_ptr<sf::RectangleShape> boton;
        int mouseX;
        int mouseY;
        bool is_MenuActive;

    protected:
        sf::Text texto;
    public:
        Menu();
        Menu(std::shared_ptr<sf::RectangleShape>, float, float, int, int, sf::Color);
        void mostrar();
        void funcion();
        float getposX();
        float getposY();
        float getAncho();
        float getAlto();
        int getMouseX();
        int getMouseY();
        bool getEstado();
        bool getEstadoFalse();
        void setIsMenuActive(bool);
        void pressed(int);
        void setText(const std::string& , const sf::Font& , unsigned int , const sf::Color&);
        
        sf::Text getTexto();
        sf::RectangleShape getboton();
};
#endif