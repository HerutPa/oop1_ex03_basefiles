#include "Door.h"

Door::Door() {
    m_type = 'D';
}

void Door::init() {
    m_rec.setSize(sf::Vector2f(70.f, 70.f));
    m_texture.loadFromFile("door.png");
    m_rec.setTexture(&m_texture);
    m_rec.setPosition(sf::Vector2f(1065, 90));
}