#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Row.h"
#include <row.idl>
//#include <fstream>

enum texture { WALL = 0, DOOR, CAT, MOUSE, CHEESE, PRESENT, KEY, ERASE, RESET, SAVE };

class Board
{
public:
	Board(int, int);
	const sf::RectangleShape CreateRectangle(const int row, const int col) const;
	void SetRow(const int row);
	void SetCol(const int col);
	/*void setCol(int);
	void setRow(int);*/
	//void init(int, int);
	const int getCol();
    const int getRow();
	void setSize();
	sf::RectangleShape& getMRec();
	void initMatrix();
	void init();

	void InitTextures();
	void initWithGivenMatrix(std::ifstream& m_ifile);



private:
	int m_row;
	int m_col;
	std::vector< Row> m_matrixVector;
	sf::RectangleShape* m_cellBoard;
	sf::RectangleShape m_rec;
	sf::Texture m_textures[7]; // the board textures


};