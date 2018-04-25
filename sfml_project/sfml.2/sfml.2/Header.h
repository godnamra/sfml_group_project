#pragma once


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





//CHESS PIECES
enum CLASS { pawn, knight, bishop, rook, queen, king };


class piece {
	piece();
	~piece(); 

	//TODO Might need to return value
	virtual void movement();

	CLASS getType();
	void setType(CLASS c);
private:
	CLASS type;
};



class Pawn :
	public piece {
	Pawn();
	~Pawn();

	void movement();


};

class Bishop :
	public piece {
	Bishop();
	~Bishop();

	void movement();


};

class King :
	public piece {
	King();
	~King();

	void movement();


};
class Queen :
	public piece {
	Queen();
	~Queen();

	void movement();


};

class Rook :
	public piece {
	Rook();
	~Rook();

	void movement();
};
