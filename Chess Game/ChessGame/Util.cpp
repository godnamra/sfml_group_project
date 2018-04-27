#include "Util.h"
#include <SFML/Graphics.hpp>
#include <time.h>




 std::string Util::convToChessSquare(Vector2f v, int size)
{
	std::string s = "";
	s += char(v.x / size + 97);
	s += char(7 - v.y / size + 49);
	return s;
}

 Vector2f Util::toCoord(char a, char b, int size)
{
	float x = float(a) - 97;
	float y = 7 - float(b) + 49;
	return Vector2f(x * size, y * size);
}



