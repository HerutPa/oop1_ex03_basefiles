#include "Controller.h"

//constructor
Controller::Controller()
    :m_window(sf::VideoMode(1200, 900), "Mouse&Cat Editor")
{
    m_background.loadFromFile("background.png");
    m_background.setSmooth(true);
    sf::Sprite s1(m_background);
    s1.scale(sf::Vector2f(1.2f, 1.2f));
    m_window.clear(sf::Color::Color(255, 255, 230));
    m_window.draw(s1);
    m_window.display();
}

void Controller::run()
{
    //sets the background sprit
    sf::Sprite s1(m_background);
    s1.scale(sf::Vector2f(1.2f, 1.2f));
    init();
   

    while (m_window.isOpen())
    {
        //clear and draw
        m_window.clear(sf::Color::Color(255, 255, 230));
        m_window.draw(s1);
        m_board.Draw(m_window);
        //DrawToolBar();
        m_window.display();

        
    }
}





void Controller::init()
{
    if (!m_ifile.fail()) //if file opend
    {
        m_board.initWithGivenMatrix(m_ifile);//reset the matrix with the file
    }
    else
    {
        m_board.setSize();
        m_board.initMatrix();
    }

    m_window.setSize(sf::Vector2u(1200, 900));
    m_ToolBar.SetSize(200, 900);
    //m_ToolBar.init();
    }

