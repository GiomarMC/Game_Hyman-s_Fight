#ifndef GAME_VIEW_CONTROLLER
#define GAME_VIEW_CONTROLLER

#include <SFML/Graphics.hpp>
#include <type_traits>
#include "character_view.h"
#include "menu.h"

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
    public:
        Game_View();
        float getDeltatime();
        void FrameLimit();
        template <typename U>
        void drawCharacter(const U&);  
        void display();
        bool IsOpen();
        void close();
        void clear();
        bool pollEvent(sf::Event&);
        sf::RenderWindow& getWindow();
        bool getMenuActive() const;
        void setMenuActive(bool);
        void drawBackground();
};

template <class T> Game_View<T>::Game_View():window(sf::VideoMode(800,600), "Hyman's Fight"), character_view("Images\\character.png")
{
    if(!backgroundTexture.loadFromFile("Images\\stadio.jpg"))
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
    return clock.restart().asSeconds()*4;
}

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
        character_view.setPosition(characterptr.getX(),characterptr.getY());
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

#endif