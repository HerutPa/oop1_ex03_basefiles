#include "Wall.h"

Wall::Wall() 
{
    m_type = '#';
}

void Wall::init()
{
    m_rec.setSize(sf::Vector2f(70.f, 70.f));
    m_texture.loadFromFile("wall.png");
    m_rec.setTexture(&m_texture);
    m_rec.setPosition(sf::Vector2f(1065, 10));
}