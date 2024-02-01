#include "Row.h"

Row::Row(int size, const Tile& value)
{
	m_ptr = new Tile[size];
	for (int i = 0; i < size; i++)
	{
		m_ptr[i] = value;
	}
}
