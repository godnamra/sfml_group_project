#include <SFML/Graphics.hpp>
using namespace sf;

#include "Header.h"






char Square::getCheckerContent()
{
	return contains;
}

class Board
{
public:
	char getSquareContent(int x, int y);
private:
	Square squares[8][8];
};

char Board::getSquareContent(int x, int y)
{
	return squares[y][x].getCheckerContent();
}

int main(void)
{

}