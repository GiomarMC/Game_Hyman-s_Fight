#ifndef GAME_VIEW_CONTROLLER
#define GAME_VIEW_CONTROLLER

#include <SFML/Graphics.hpp>
#include <type_traits>
#include "character_view.h"

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
};

template <class T> Game_View<T>::Game_View():window(sf::VideoMode(800,600), "Hyman's Fight"), character_view("E:\\Game_final_CC2\\character.png")
{
    
}

template <class T> float Game_View<T>::getDeltatime()
{
    return clock.restart().asSeconds()*4;
}

template <class T> void Game_View<T>::FrameLimit()
{
    window.setFramerateLimit(60);
}

template <typename T>
template <typename U>
void Game_View<T>::drawCharacter(const U& character)
{
    if constexpr (is_character<U>::value)
    {
        character_view.setPosition(character.getX(),character.getY());
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

#endif