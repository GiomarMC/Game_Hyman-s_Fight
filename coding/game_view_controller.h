#ifndef GAME_VIEW_CONTROLLER
#define GAME_VIEW_CONTROLLER

#include <SFML/Graphics.hpp>
#include <type_traits>
#include <unordered_set>
#include "character_view.h"
#include "Menu_View.h"
#include "plataforma_view.h"

class Character;

template<typename T>
struct is_character : std::false_type {};

template <>
struct is_character<Character> : std::true_type {};

template<typename T>
class Game_View
{
    private:
        sf::RenderWindow window;
        sf::Clock clock;
        Character_view character_view;
        bool isMenuActive;
        sf::Texture backgroundTexture;
        sf::Sprite backgroundSprite;
        Plataforma_view plataformaView;
        sf::Event event;
        sf::Keyboard::Key ultimatecla;
        std::unordered_set<sf::Keyboard::Key> pressedKeys;
        float deltatime;
        int row;
        bool is_move, is_Jumping;
        float posX, posY;
        bool is_Left, is_Right;
    public:
        Game_View();
        float getPosX() const; 
        float getPosY() const;
        bool getIs_Left() const;
        bool getIs_Right() const;
        float getMouseX() const;
        float getMouseY() const;
        float getDeltatime();
        bool isJumping() const;
        void FrameLimit();
        template <typename U>
        void drawCharacter(const U&);  
        void display();
        bool IsOpen();
        void close();
        void clear();
        bool pollEvent(sf::Event&);
        void update();
        void handleEvents();
        sf::RenderWindow& getWindow();
        bool getMenuActive() const;
        void setMenuActive(bool);
        void drawBackground();
        void drawPlataform(float, float, float, float);
};

template <class T> Game_View<T>::Game_View():window(sf::VideoMode(800,600), "Hyman's Fight"), character_view("Images\\spritesheet.png"), plataformaView("Images\\plataforma_1.png"),
is_move(true), is_Jumping(false), is_Left(false), is_Right(false), posX(0), posY(0)
{
    if(!backgroundTexture.loadFromFile("Images\\cielo_azul.jpg"))
    {
        std::cerr << "Error al cargar la imagen de fondo";
    }
    backgroundSprite.setTexture(backgroundTexture);

    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = backgroundTexture.getSize();
    backgroundSprite.setScale(static_cast<float>(windowSize.x) / textureSize.x, static_cast<float>(windowSize.y) / textureSize.y);

}

template <class T> float Game_View<T>::getDeltatime()
{
    deltatime = clock.restart().asSeconds()*4;
    return deltatime;
}

template <class T> float Game_View<T>::getPosX() const {return posX;}

template <class T> float Game_View<T>::getPosY() const {return posY;}

template <class T> bool Game_View<T>::getIs_Left() const {return is_Left;}

template <class T> bool Game_View<T>::getIs_Right() const {return is_Right;}

template <class T> bool Game_View<T>::isJumping() const {return is_Jumping;}

template <class T> void Game_View<T>::FrameLimit()
{
    window.setFramerateLimit(60);
}

template <class T>
template <typename U>
void Game_View<T>::drawCharacter(const U& characterptr)
{
    drawBackground();
    if constexpr (is_character<U>::value)
    {
        //character_view.setDimension(characterptr.getWidth(), characterptr.getHeigth());
        character_view.setPosition(characterptr.getX(),characterptr.getY());
        if (is_move == false) {
            character_view.moveCharacterNone(row, deltatime);
        }
        else
        {
            character_view.printCharacter(row);
        }
                
        character_view.draw(window);
    }
}

template <class T> void Game_View<T>::display()
{
    window.display();
}

template <class T> bool Game_View<T>::IsOpen()
{
    return window.isOpen();
}

template <class T> void Game_View<T>::close()
{
    window.close();
}

template <class T> void Game_View<T>::clear()
{
    window.clear();
}

template <class T> bool Game_View<T>::pollEvent(sf::Event& event)
{
    return window.pollEvent(event);
}

template <class T> void Game_View<T>::handleEvents()
{
    while (pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            close();
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
            close();
        }
        if(event.type == sf::Event::KeyPressed)
        {
            pressedKeys.insert(event.key.code);
        }
        if(event.type == sf::Event::KeyReleased)
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

template <class T> void Game_View<T>::update()
{
    if(pressedKeys.count(sf::Keyboard::Left) > 0)
    {
        posX = -2;
        posY = 0;
        is_Left = true;
        ultimatecla = sf::Keyboard::Right;
        row = 2;
    }
            
    else if(pressedKeys.count(sf::Keyboard::Right) > 0)
    {
        posX = 2;
        posY = 0;
        is_Right = true;
        ultimatecla = sf::Keyboard::Left;
        row = 3;
    }
            
    else if(pressedKeys.count(sf::Keyboard::Up) > 0)
    {
        is_Jumping = true;
        if (ultimatecla == sf::Keyboard::Right)
            row = 4;
        else
            row = 4;
    }
    else if(pressedKeys.count(sf::Keyboard::Down) > 0) //PELEA
    {
        //characterptr -> fight();
        if (ultimatecla == sf::Keyboard::Right)
            row = 1; //6
        else 
            row = 0; //7
    }
    else
    {
        posX = 0;
        posY = 0;
        is_Jumping = false;
    }
}

template<class T> sf::RenderWindow &Game_View<T>::getWindow()
{
    return window;
}

template <class T> bool Game_View<T>::getMenuActive() const
{
    return isMenuActive;
}

template <class T> void Game_View<T>::setMenuActive(bool isActive)
{
    isMenuActive = isActive;
}

template <class T> void Game_View<T>::drawBackground()
{
    window.draw(backgroundSprite);
}

template<class T> void Game_View<T>::drawPlataform(float x, float y, float width, float height)
{
    plataformaView.setPlataformData(x,y,width,height);
    plataformaView.drawPlataform(window);
}

#endif