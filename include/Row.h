#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Tile.h"

class Row
{
public:
	explicit Row(int size = 0, const Tile& value = Tile());
	//void init();

private:
	Tile *m_ptr;
	
};