#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Row
{
public:

	Row();
	Row(int, const sf::RectangleShape& value);
	Row(int size);
	Row(const Row& other);
	Row& operator=(const Row& other);
	//void init();
	//explicit Row(int size, const sf::RectangleShape& value);
	void push_back(const sf::RectangleShape& value);
	const sf::RectangleShape& at(int index) const;
	const char getChar(int index) const;
	void writeOnIndex(int index, char obj);
	sf::RectangleShape& at(int index);

	int getSize() const;

	bool isEmpty() const;

	~Row();



private:
	sf::RectangleShape* m_cell;
	
	sf::RectangleShape m_cellBoard;
	int m_size;
	char *m_char;
};

