#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>


#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

class GameObject
{
protected:
    sf::RectangleShape m_rec;
    char m_type;
    sf::Texture m_texture;

public:
    virtual void init() = 0;
    virtual const sf::RectangleShape& GetRec() const
    {
        return m_rec;
    }
    virtual const char GetChar() const
    {
        return m_type;
    }
};

#endif // GAME_OBJECT_H