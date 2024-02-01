#include "board.h"
#include "Row.h"

Board::Board(int row, int col)
	:m_row (row), m_col (col)
{
	for (int row = 0; row < m_row; row++)
	{
		m_matrixVector[row].push_back(Row(col, m_tile));

	}
}

int Board::getCol()
{
	return m_col;
}

int Board::getRow()
{
	return m_row;
}

void Board::setSize()
{
	std::cout << "please enter row and col: ";
	std::cin >> m_row >> m_col;
	while (m_col > 18 || m_row > 20 || m_col < 1 || m_row < 1) // correct the size
	{
		std::cout << "the maximum c/r size is 1-18/1-20 please enter again col and row: ";
		std::cin >> m_row >> m_col;
	}
}



