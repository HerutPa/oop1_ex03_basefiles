#include "board.h"
#include "Row.h"

Board::Board(int row, int col)
	:m_row(row), m_col(col)
{
	for (int row = 0; row < m_row; row++)
	{
		m_rec.setSize((sf::Vector2f(50.f, 50.f)));
		//auto rec = sf::RectangleShape(SIZE_OF_CELL);

        m_rec.setOutlineColor(sf::Color::Color(102, 102, 102));
        m_rec.setOutlineThickness(1.f);
        m_rec.setFillColor(sf::Color::Transparent);
               
	    Row m_cellBoard(getCol(), getMRec());
		m_matrixVector[row].push_back(m_cellBoard);
		
	}
}

void Board::InitTextures()
{
	m_textures[WALL].loadFromFile("wall.jpg");
	m_textures[DOOR].loadFromFile("door.png");
	m_textures[CAT].loadFromFile("cat.png");
	m_textures[MOUSE].loadFromFile("mouse.png");
	m_textures[CHEESE].loadFromFile("sheese.png");
	m_textures[PRESENT].loadFromFile("present.png");
	m_textures[KEY].loadFromFile("key.png");
}

const sf::RectangleShape Board::CreateRectangle(const int row, const int col) const
{
	sf::RectangleShape rec;

	//Position
	rec.setSize(sf::Vector2(50.f, 50.f));
	rec.setPosition((float)((1000 - m_row * 50.f) / 2 + (row * 50.f)),
		(float)((900 - m_col * 50.f) / 2 + (col * 50.f)));

	//Style
	rec.setOutlineColor(sf::Color::Color(102, 102, 102));
	rec.setOutlineThickness(1.f);
	rec.setFillColor(sf::Color::Transparent);

	return rec;
}

void Board::SetRow(const int row)
{
	m_row = row;
}

void Board::SetCol(const int col)
{
	m_col = col;
}
const int Board::getCol()
{
	return m_col;
}

const int Board::getRow()
{
	return m_row;
}


void Board::setSize()
{
	std::cout << "please enter row and col: ";
	std::cin >> m_row >> m_col;
}

sf::RectangleShape& Board::getMRec()
{
	return m_rec;
}


void Board::initMatrix()
{
	// initial the matrix with char ' ' to create empty board
	m_matrixVector.clear();
	m_matrixVector.resize(m_row);
	for (auto& row : m_matrixVector) //קח מצביע לתוך הוקטור ותעבור שורה שורה
	{
		Row temp_row(m_col); //יצירת שורה ריקה

		row.operator= (temp_row) ; //הכנסו את השורה לתוך הוקטור

		/*std::vector < char > vector_row;
		for (int col = 0; col < m_col; ++col)
		{
			vector_row.push_back(' ');
		}
		m_matrix.push_back(vector_row);*/
	}
}


