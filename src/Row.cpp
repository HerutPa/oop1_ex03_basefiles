#include "Row.h"

Row::Row()
{
}

Row::Row (int size, const sf::RectangleShape& value)
{
    m_size = size;
	m_cell = new sf::RectangleShape[size]();
	for (int i = 0; i < m_size; i++)
	{
        auto startPosition = value.getPosition();
        auto cellsize = value.getSize();

        m_cell[i] = value;
        m_cell[i].setPosition(startPosition.x + cellsize.x * i, startPosition.y );
		
    }
}

Row::Row(int size)
{
    m_size = size;
    m_char = new char[m_size];
    for (int i = 0; i < m_size; i++)
    {
        m_char[i] = ' ';
    }
}


// בנאי העתקה
Row::Row(const Row& other) : m_size(other.m_size)
{
    m_cell = new sf::RectangleShape[m_size];
    for (int i = 0; i < m_size; i++)
    {
        m_cell[i] = other.m_cell[i];
    }
}

// אופרטור השמה
Row& Row::operator=(const Row& other) 
{
    if (this != &other)
    {
        delete[] m_cell; // שחרור זיכרון ישן
        m_size = other.m_size;
        m_cell = new sf::RectangleShape[m_size];
        m_char = new char[m_size];
        for (int i = 0; i < m_size; i++)
        {
            m_cell[i] = other.m_cell[i];
            m_char[i] = other.m_char[i];
        }
    }
    return *this;
}

// יוסיף איבר לסוף השורה
void Row::push_back(const sf::RectangleShape& value) 
{
    sf::RectangleShape* newData = new sf::RectangleShape[m_size + 1];
    for (int i = 0; i < m_size; ++i) {
        newData[i] = m_cell[i];
    }
    newData[m_size] = value;
    delete[] m_cell;
    m_cell = newData;
    m_size++;
}

// קבלת ערך במיקום נתון
const sf::RectangleShape& Row::at(int index) const
{
    return m_cell[index];
}

// קבלת ערך במיקום נתון
const char Row::getChar(int index) const
{
    return m_char[index];
}

// קבלת ערך במיקום נתון
void Row::writeOnIndex(int index, char obj)
{
    m_char[index] = obj;


}

// קבלת גודל השורה
int Row::getSize() const {
    return m_size;
}

// בדיקה האם השורה ריקה
bool Row::isEmpty() const {
    return m_size == 0;
}

//// הדפסת השורה
//void Row::printRow() const {
//    for (int i = 0; i < size; ++i) {
//        std::cout << rowData[i].getValue() << " ";
//    }
//    std::cout << std::endl;
//}

// דסטרקטור לשחרור את הזיכרון
Row::~Row() {
    delete[] m_cell;
}

