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


// ���� �����
Row::Row(const Row& other) : m_size(other.m_size)
{
    m_cell = new sf::RectangleShape[m_size];
    for (int i = 0; i < m_size; i++)
    {
        m_cell[i] = other.m_cell[i];
    }
}

// ������� ����
Row& Row::operator=(const Row& other) 
{
    if (this != &other)
    {
        delete[] m_cell; // ����� ������ ���
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

// ����� ���� ���� �����
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

// ���� ��� ������ ����
const sf::RectangleShape& Row::at(int index) const
{
    return m_cell[index];
}

// ���� ��� ������ ����
const char Row::getChar(int index) const
{
    return m_char[index];
}

// ���� ��� ������ ����
void Row::writeOnIndex(int index, char obj)
{
    m_char[index] = obj;


}

// ���� ���� �����
int Row::getSize() const {
    return m_size;
}

// ����� ��� ����� ����
bool Row::isEmpty() const {
    return m_size == 0;
}

//// ����� �����
//void Row::printRow() const {
//    for (int i = 0; i < size; ++i) {
//        std::cout << rowData[i].getValue() << " ";
//    }
//    std::cout << std::endl;
//}

// �������� ������ �� �������
Row::~Row() {
    delete[] m_cell;
}

