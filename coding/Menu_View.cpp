#include "Menu_View.h"

Menu::Menu(): Alto(0), Ancho(0), is_MenuActive(true)
{

}
Menu::Menu(sf::RectangleShape& button, float ancho, float alto, int x, int y, sf::Color color): Ancho(ancho), 
Alto(alto), posX(x), posY(y), boton(&button)
{
    button.setPosition(posX, posY);
    button.setFillColor(color);
}

float Menu::getposX() { return posX; }
float Menu::getposY() { return posY; }
float Menu::getAncho() { return Ancho; }
float Menu::getAlto() { return Alto; }
bool Menu::getEstado() { return estado; }
bool Menu::getEstadoFalse() { estado = false; return estado;}
int  Menu::getMouseX() {return mouseX;}
int Menu::getMouseY() {return mouseY;}
sf::Text Menu::getTexto() {return texto;}
sf::RectangleShape Menu::getboton() {return *boton;}
void Menu::setIsMenuActive(bool state) {is_MenuActive = state;}

void Menu::funcion() {
    estado = true;
}

void Menu::pressed(int i) {
    boton->setSize(sf::Vector2f(Ancho + (10 * i), Alto + (10 * i)));
    boton->setPosition(posX - (5 * i), posY - (5 * i));
}
void Menu::setText(const std::string& str, const sf::Font& font, unsigned int characterSize, const sf::Color& color) {
    texto.setFont(font);
    texto.setString(str);
    texto.setCharacterSize(characterSize);
    texto.setFillColor(color);

    // Centramos el texto dentro del botón.
    sf::FloatRect bounds = texto.getLocalBounds();
    float textX = posX + (Ancho - bounds.width) / 2.0f;
    float textY = posY + (Alto - bounds.height) / 2.0f;
    texto.setPosition(textX, textY);
}


void Menu::mostrar()
{
    unsigned int ancho = 1200, alto = 800;
    sf::RenderWindow window(sf::VideoMode(ancho, alto), "Menu");

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Images/map.jpg")) {
        std::cerr << "Error al cargar la imagen de fondo." << std::endl;
    }

    sf::Sprite backgroundSprite(backgroundTexture);
    sf::Vector2u windowSize = window.getSize();
    backgroundSprite.setScale(
        static_cast<float>(windowSize.x) / backgroundTexture.getSize().x,
        static_cast<float>(windowSize.y) / backgroundTexture.getSize().y
    );
    sf::RectangleShape mp1(sf::Vector2f(300.0f, 300.0f));
    sf::RectangleShape mp2(sf::Vector2f(300.0f, 300.0f));
    sf::RectangleShape mp3(sf::Vector2f(300.0f, 300.0f));
    sf::RectangleShape b1(sf::Vector2f(100.0f, 100.0f));
    sf::RectangleShape b2(sf::Vector2f(110.0f, 100.0f));
    sf::RectangleShape b3(sf::Vector2f(100.0f, 100.0f));
    sf::RectangleShape* cuadros = new sf::RectangleShape[6];

    Menu* square = new Menu[6];


    for (int i = 0; i < 6; i++) {
        cuadros[i] = b2;
        Menu boton3(cuadros[i], 100.0f, 110.0f, 50 + 200 * i, 300, sf::Color::Black);
        square[i]=boton3;
    }


    sf::Font font;
    if (!font.loadFromFile("Fuentes/Alice.ttf")) {
        std::cerr << "Error al cargar la fuente." << std::endl;
    }

    Menu boton1(b1, 100.0f, 100.0f, ancho / 2, alto / 2, sf::Color::Yellow);
    Menu boton2(b3, 100.0f, 100.0f, 1000, 630, sf::Color::Red);
    Menu map1(mp1,300.0f, 300.0f, 100, 100, sf::Color::Yellow);
    Menu map2(mp2,300.0f, 300.0f, 800, 100, sf::Color::Yellow);
    Menu map3(mp3,300.0f, 300.0f, 450, 450, sf::Color::Yellow);

    boton1.setText("Iniciar", font, 24, sf::Color::Black);
    boton2.setText("Atras", font, 24, sf::Color::Black);

    sf::Clock marca_tiempo;
    sf::Time intervalo;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || !is_MenuActive)
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                mouseX = event.mouseButton.x;
                mouseY = event.mouseButton.y;
                if (boton1.getEstado())
                {
            
                }
                else if (boton1.getEstado())
                {
                    map1.getEstadoFalse();
                    map2.getEstadoFalse();
                    map3.getEstadoFalse();
                }
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

            if (mousePosition.x >= boton1.getposX() && mousePosition.x <= boton1.getposX() + boton1.getAncho() && mousePosition.y >= boton1.getposY() && mousePosition.y <= boton1.getposY() + boton1.getAlto() && boton1.getEstado() == false) {
                if (event.type == sf::Event::MouseButtonPressed) {
                    boton1.funcion();
                    boton2.getEstadoFalse();
                }
                boton1.pressed(1);
            }
            else
                boton1.pressed(0);

            if (mousePosition.x >= boton2.getposX() && mousePosition.x <= boton2.getposX() + boton2.getAncho() && mousePosition.y >= boton2.getposY() && mousePosition.y <= boton2.getposY() + boton2.getAlto() && boton2.getEstado() == false) {
                if (event.type == sf::Event::MouseButtonPressed) {
                    boton2.funcion();
                    boton1.getEstadoFalse();
                }
                boton2.pressed(1);
            }
            else
                boton2.pressed(0);
            for(int i = 0; i<6; i++){
                if (mousePosition.x >= square[i].getposX() && mousePosition.x <= square[i].getposX() + square[i].getAncho() && mousePosition.y >= square[i].getposY() && mousePosition.y <= square[i].getposY() + square[i].getAlto() && square[i].getEstado() == false && boton1.getEstado()==true) {
                    if (event.type == sf::Event::MouseButtonPressed) {
                        square[i].funcion();
                       
                    }
                    square[i].pressed(1);
                    boton2.getEstadoFalse();
                }
                else
                    square[i].pressed(0);
            }
            if (mousePosition.x >= map1.getposX() && mousePosition.x <= map1.getposX() + map1.getAncho() && mousePosition.y >= map1.getposY() && mousePosition.y <= map1.getposY() + map1.getAlto()) {
                    if (event.type == sf::Event::MouseButtonPressed) {
                        map1.funcion();
                       
                    }
                    map1.pressed(1);
                }
                else
                    map1.pressed(0);

            if (mousePosition.x >= map2.getposX() && mousePosition.x <= map2.getposX() + map2.getAncho() && mousePosition.y >= map2.getposY() && mousePosition.y <= map2.getposY() + map2.getAlto()) {
                    if (event.type == sf::Event::MouseButtonPressed) {
                        map2.funcion();
                       
                    }
                    map2.pressed(1);
                }
                else
                    map2.pressed(0);

            if (mousePosition.x >= map3.getposX() && mousePosition.x <= map3.getposX() + map3.getAncho() && mousePosition.y >= map3.getposY() && mousePosition.y <= map3.getposY() + map3.getAlto()) {
                    if (event.type == sf::Event::MouseButtonPressed) {
                        map3.funcion();
                       
                    }
                    map3.pressed(1);
                }
                else
                    map3.pressed(0);
        }

        intervalo = marca_tiempo.restart();
        float intervalo_s = intervalo.asSeconds();

        window.clear(sf::Color::Black);
        window.draw(backgroundSprite);

        if (boton1.getEstado()) {
            for (int i = 0; i < 6; i++){
                if(!(square[0].getEstado() || square[1].getEstado() || square[2].getEstado() || square[3].getEstado() || square[4].getEstado() || square[5].getEstado()))
                    window.draw(square[i].getboton());

            }
            if(!(square[0].getEstado() || square[1].getEstado() || square[2].getEstado() || square[3].getEstado() || square[4].getEstado() || square[5].getEstado()))
                window.draw(boton2.getboton());
        }

        if (!boton1.getEstado() || boton2.getEstado()) {
            window.draw(b1);
        }

        // Dibujar el texto en el botón amarillo solo cuando no está presionado
        if (!boton1.getEstado()) {
            window.draw(boton1.getTexto());
        }
        if (!boton2.getEstado() && boton1.getEstado() && !(square[0].getEstado() || square[1].getEstado() || square[2].getEstado() || square[3].getEstado() || square[4].getEstado() || square[5].getEstado())) {
            window.draw(boton2.getTexto());
        }
        if (boton1.getEstado()){
            for(int i=0; i<6; i++){
                if(square[i].getEstado()){
                    window.draw(map1.getboton());
                    window.draw(map2.getboton());
                    window.draw(map3.getboton());
                }
            }
        }
        window.display();
        }
    }
}