#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include "Board.h"
//#include "ToolBar.h"


class Controller
{
public:
    Controller();
    void run();
    void init();


private:
    //Board m_board;
    sf::RenderWindow m_window;
    sf::Texture m_background;
    std::ifstream m_ifile = std::ifstream("Board.txt");
    std::ofstream m_ofile;

    //ToolBar m_ToolBar;
};