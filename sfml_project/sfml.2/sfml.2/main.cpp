#include <SFML/Graphics.hpp>
using namespace sf;

class Coordinates
{
public:
	Coordinates(int x1 = 0, int x2 = 0)
	{}
	void setxy(int x1, int y1);
	int getX();
	int getY();
private:
	int x;
	int y;
};
int Coordinates::getX()
{
	return x;
}
int Coordinates::getY()
{
	return y;
}
void Coordinates::setxy(int x1, int y1)
{
	x = x1;
	y = y1;
}


class Piece
{
public:
private:

};

class Player
{

};
class Square : public RectangleShape
{
public:
	Square(Vector2f &pos, Color &c, Vector2f &dim)
	{
		setPosition(pos);
		setFillColor(c);
		setSize(dim);
	}
	char getCheckerContent();
private:
	char contains;
};
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