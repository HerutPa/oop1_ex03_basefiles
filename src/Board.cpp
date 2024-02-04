//#include "board.h"
//#include "Row.h"
//
//Board::Board(int row, int col)
//	:m_row(row), m_col(col)
//{
//	for (int row = 0; row < m_row; row++)
//	{
//		m_rec.setSize((sf::Vector2f(50.f, 50.f)));
//		//auto rec = sf::RectangleShape(SIZE_OF_CELL);
//
//        m_rec.setOutlineColor(sf::Color::Color(102, 102, 102));
//        m_rec.setOutlineThickness(1.f);
//        m_rec.setFillColor(sf::Color::Transparent);
//               
//	    Row m_cellBoard(getCol(), getMRec());
//		m_matrixVector[row].push_back(m_cellBoard);
//		
//	}
//}
//
//
//
//void Board::SetRow(const int row)
//{
//	m_row = row;
//}
//
//void Board::SetCol(const int col)
//{
//	m_col = col;
//}
//const int Board::getCol()
//{
//	return m_col;
//}
//
//const int Board::getRow()
//{
//	return m_row;
//}
//
//
//void Board::setSize()
//{
//	std::cout << "please enter row and col: ";
//	std::cin >> m_row >> m_col;
//}
//
//sf::RectangleShape& Board::getMRec()
//{
//	return m_rec;
//}
//
//
//
