#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;
class Util
{
public:
	static std::string convToChessSquare(Vector2f v, int size);
	static Vector2f toCoord(char a, char b, int size);
};

