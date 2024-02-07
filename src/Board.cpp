#include "Board.h"
#include "Row.h"
#include <fstream>


Board::Board()
{
    m_textures[WALL].loadFromFile("wall.jpg");
    m_textures[DOOR].loadFromFile("door.png");
    m_textures[CAT].loadFromFile("cat.png");
    m_textures[MOUSE].loadFromFile("mouse.png");
    m_textures[CHEESE].loadFromFile("sheese.png");
    m_textures[PRESENT].loadFromFile("present.png");
    m_textures[KEY].loadFromFile("key.png");

}
void Board::initMatrix()
{
	// initial the matrix with char ' ' to create empty board
	m_matrixVector.clear();
	m_matrixVector.resize(m_row);
	for (auto& row : m_matrixVector) //קח מצביע לתוך הוקטור ותעבור שורה שורה
	{
		Row temp_row(m_col); //יצירת שורה ריקה
		row.operator= (temp_row); //הכנסו את השורה לתוך הוקטור

		/*std::vector < char > vector_row;
		for (int col = 0; col < m_col; ++col)
		{
			vector_row.push_back(' ');
		}
		m_matrix.push_back(vector_row);*/
	}
}

void Board::initWithGivenMatrix(std::ifstream &m_ifile)
{
	m_ifile.get(); // for \n

	// Read the two integers from the file
	m_ifile >> m_row >> m_col;
	m_ifile.get(); // for \n //אולי תהיה בעייה עם הירדית שורה על מנת לקרוא את הנתונים
	m_matrixVector.clear();
	m_matrixVector.resize(m_row);
	char c;
	
	for (auto& row : m_matrixVector)
	{
		Row temp_row(m_col);
		for (int col = 0; col < m_col; col++)
		{
			m_ifile.get(c);
			temp_row.writeOnIndex(col, c);
		}
		row.operator= (temp_row);
	}
}


void Board::Draw(sf::RenderWindow &m_window)
{
    float offset = 400 ;
    int num_of_row = 0;
    for (auto& row : m_matrixVector)
    {
       
        for (int col = 0; col < m_col; ++col)
        {
            sf::Vector2f location((col*m_rec.getSize().x)+offset, num_of_row* m_rec.getSize().y);
            char type = row.getChar(col);
            switch (type)
            {
            case '#':
            {
                m_rec.setTexture(&m_textures[0]);
                m_rec.setOutlineColor(sf::Color::Color(102, 102, 102));
                m_rec.setOutlineThickness(1.f);
                m_rec.setPosition(location); //בגלל שהתפריט מגיע מצד שמאל לפני הבורד.
                m_window.draw(m_rec);
                break;
            }
            case 'D':
            {
                m_rec.setTexture(&m_textures[1]);
                m_rec.setOutlineColor(sf::Color::Color(102, 102, 102));
                m_rec.setOutlineThickness(1.f);
                m_rec.setPosition(location); //בגלל שהתפריט מגיע מצד שמאל לפני הבורד.
                m_window.draw(m_rec);
                break;
            }
            case '^':
            {
                m_rec.setTexture(&m_textures[2]);
                m_rec.setOutlineColor(sf::Color::Color(102, 102, 102));
                m_rec.setOutlineThickness(1.f);
                m_rec.setPosition(location); //בגלל שהתפריט מגיע מצד שמאל לפני הבורד.
                m_window.draw(m_rec);
                break;
            }
            case '%':
            {
                m_rec.setTexture(&m_textures[3]);
                m_rec.setOutlineColor(sf::Color::Color(102, 102, 102));
                m_rec.setOutlineThickness(1.f);
                m_rec.setPosition(location); //בגלל שהתפריט מגיע מצד שמאל לפני הבורד.
                m_window.draw(m_rec);
                break;
            }
            case '*':
            {
                m_rec.setTexture(&m_textures[4]);
                m_rec.setOutlineColor(sf::Color::Color(102, 102, 102));
                m_rec.setOutlineThickness(1.f);
                m_rec.setPosition(location); //בגלל שהתפריט מגיע מצד שמאל לפני הבורד.
                m_window.draw(m_rec);
                break;;
            }
            case '$':
            {
                m_rec.setTexture(&m_textures[5]);
                m_rec.setOutlineColor(sf::Color::Color(102, 102, 102));
                m_rec.setOutlineThickness(1.f);
                m_rec.setPosition(location); //בגלל שהתפריט מגיע מצד שמאל לפני הבורד.
                m_window.draw(m_rec);
                break;
            }
            case 'F':
            {
                m_rec.setTexture(&m_textures[6]);
                m_rec.setOutlineColor(sf::Color::Color(102, 102, 102));
                m_rec.setOutlineThickness(1.f);
                m_rec.setPosition(location); //בגלל שהתפריט מגיע מצד שמאל לפני הבורד.
                m_window.draw(m_rec);
                break;
            }

            case ' ':
                m_rec.setFillColor(sf::Color::Black);
                m_rec.setOutlineColor(sf::Color::Color(102, 102, 102));
                m_rec.setOutlineThickness(1.f);
                m_rec.setPosition(location); //בגלל שהתפריט מגיע מצד שמאל לפני הבורד.
                m_window.draw(m_rec);
                break;

            default:
                m_rec.setFillColor(sf::Color::Black);
                m_rec.setOutlineColor(sf::Color::Color(102, 102, 102));
                m_rec.setOutlineThickness(1.f);
                m_rec.setPosition(location); //בגלל שהתפריט מגיע מצד שמאל לפני הבורד.
                m_window.draw(m_rec);
                break;
            }
            num_of_row++;
        }

}


//const sf::RectangleShape Board::CreateRectangle(const int row, const int col) const
//{
//	sf::RectangleShape rec;
//
//	//Position
//	rec.setSize(sf::Vector2(50.f, 50.f));
//	rec.setPosition((float)((1000 - m_row * 50.f) / 2 + (row * 50.f)),
//		(float)((900 - m_col * 50.f) / 2 + (col * 50.f)));
//
//	//Style
//	rec.setOutlineColor(sf::Color::Color(102, 102, 102));
//	rec.setOutlineThickness(1.f);
//	rec.setFillColor(sf::Color::Transparent);
//
//	return rec;
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


