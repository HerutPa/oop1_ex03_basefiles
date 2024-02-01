#include "Controller.h"

//constructor
Controller::Controller()
    :m_window(sf::VideoMode(1200, 900), "Mouse&Cat Editor")
{
    m_background.loadFromFile("background.png");
    m_background.setSmooth(true);
    sf::Sprite s1(m_background);
    s1.scale(sf::Vector2f(1.75f, 1.75f));
    m_window.clear(sf::Color::Color(255, 255, 230));
    m_window.draw(s1);
    m_window.display();
}


//void Controller::run()
//{
//    //sets the background sprit
//    sf::Sprite s1(m_background);
//    s1.scale(sf::Vector2f(1.75f, 1.75f));
//    init();
//}
//
//
//
//void Controller::init()
//{
//    if (!m_ifile.fail()) //if file opend
//    {
//        int col, row;
//        m_ifile >> row >> col;
//        m_board.SetRow(row);
//        m_board.SetCol(col);
//        //InitWithGivenMatrix();//reset the matrix with the file
//    }
//    else
//    {
//        m_board.SetSize();
//       // InitMatrix();
//    }
//    m_board.init();
//    m_window.setSize(sf::Vector2u(1200, 900));
//    m_ToolBar.SetSize(200, 900);
//    m_ToolBar.init();
//}