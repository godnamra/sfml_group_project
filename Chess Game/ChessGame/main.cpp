#include <SFML/Graphics.hpp>
#include <time.h>
#include "Conn.hpp"
#include "Util.h"
#include <iostream>
//#include "Player.h"
#include "TileMap.h"
#include <iostream>

using namespace sf;

enum PIECES {
	bQUEEN = -1, bBISHOP = -2, bKNIGHT = -3, bROOK = -4, bPAWN = -5, bKING = 4,
	wQUEEN = -7, wROOK = 6, wKING = -6, wKNIGHT = 7, wBISHOP = 8, wPAWN = 11
};

void move(std::string str)
{
	Vector2f oldPos = Util::toCoord(str[0], str[1], 56);
	Vector2f newPos = Util::toCoord(str[2], str[3], 56);

	//castling       //if the king didn't move
	//if (str == "e1g1") if (position.find("e1") == -1) move("h1f1");
	//if (str == "e8g8") if (position.find("e8") == -1) move("h8f8");
	//if (str == "e1c1") if (position.find("e1") == -1) move("a1d1");
	//if (str == "e8c8") if (position.find("e8") == -1) move("a8d8");
}
void resetMoves(int * moves[]) {
	for (int i = 0; i < 64; i++)
		*moves[i] = 0;
}


int coordToListIndex(Vector2i co) {
	return co.y * 8 + co.x;
}
bool validMove(PIECES piece, Vector2i coord, int moveMap[], int tile[], Vector2i oldPos) {
	/*
	Moves will be recorded ass follows
	0 - cant move
	-1 - piece location
	1 can move
	2 can attack
	*/
	int index = coordToListIndex(coord);
	Vector2i tempV;
	std::vector<Vector2i> coordList;

	switch (piece) {
		case bQUEEN:
			break;
		case bBISHOP:
			break;
		case bKNIGHT:
			break;
		case bROOK:
			break;
		case bPAWN: {

		}
					break;
		case bKING:
			break;


		case wQUEEN:
		{

		}
		break;
		case wROOK:
			break;
		case wKING:
			break;
		case wKNIGHT:
			break;
		case wBISHOP:
			break;
		case wPAWN: {
			if (oldPos .y == 6) {
				coordList.push_back(Vector2i(oldPos.x - 2, oldPos.y));
			}
			coordList.push_back(Vector2i(oldPos.x - 1, oldPos.y));
		}
					break;		
	}
	for (Vector2i temp : coordList)
		if (coord.x == temp.x && coord.y == temp.y)
			return true;
	return false;
}



int main()
{
	//numbers arent random, two of the tiles
	//chosen to be taken from the cheesBoard.jpg 
	//tileset
	//Player player;
	//Player computer;

	int board[64] =
	{
		-1,-5,-1,-5,-1,-5,-1,-5,
		-5,-1,-5,-1,-5,-1,-5,-1,
		-1,-5,-1,-5,-1,-5,-1,-5,
		-5,-1,-5,-1,-5,-1,-5,-1,
		-1,-5,-1,-5,-1,-5,-1,-5,
		-5,-1,-5,-1,-5,-1,-5,-1,
		-1,-5,-1,-5,-1,-5,-1,-5,
		-5,-1,-5,-1,-5,-1,-5,-1,
	};

	int moveMap[64]{
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
	};

	//becuase of how the tilemap fct retrieves textures the following enum will allow for the 
	//wanted textures to appear

	

	
	int tile[64] =
	{
		bROOK,bKNIGHT,bBISHOP,bQUEEN,bKING,bBISHOP,bKNIGHT,bROOK,
		bPAWN,bPAWN,bPAWN,bPAWN,bPAWN,bPAWN,bPAWN,bPAWN,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		wPAWN,wPAWN,wPAWN,wPAWN,wPAWN,wPAWN,wPAWN,wPAWN,
		wROOK,wKNIGHT,wBISHOP,wQUEEN,wKING,wBISHOP,wKNIGHT,wROOK,
	};


	/* for reference
	black queen -1
	black bishop -2
	black knight -3
	black rook -4
	black pawn -5
	black king 4

	white queen -7
	white rook 6
	white king -6
	white knight 7
	white bishop 8
	white pawn 11
	*/

	int size = 56;
	Util util;
	Vector2f offset(26, 26);

	int scaleFactor = 1;
	Sprite sprites[32];
	std::string position = "";
	
	//window
	RenderWindow window(VideoMode(size * 8 + 100, size * 8), "Chess 2D");
	View view(sf::FloatRect(0, 0, size * 8 + 100, size * 8));

	//stockfish chess AI engine
	ConnectToEngine();

	bool isMove = false;
	float dx = 0, dy = 0;

	Vector2i oldPos, newPos;
	std::string str;

	int n = 0;
	
	
	int lastClicked = -1;


	/*////////////////////////////////////////////////////////
	  / Main logic loop, loops on the window being open.     /
	 *////////////////////////////////////////////////////////
	while (window.isOpen())
	{
		Vector2i mousePos = Mouse::getPosition(window);
		Event e; //event obj for accessing window events
		
		//function is only true if an event is waiting on the queue
		while (window.pollEvent(e))
		{
			/*//////////////////
			EVENTS AND HANDLING
			*///////////////////
			if (e.type == Event::Resized) {
				window.setView(view);
			}
			if (e.type == Event::Closed)
				window.close();

			//select sprite
			if (e.type == Event::MouseButtonPressed)
				if (e.key.code == Mouse::Left)
				{
					sf::Vector2i pixelPos = sf::Mouse::getPosition(window); //mousepos is based off of window size, which can be larger or smaller than 468x468
					// convert it to world coordinates
					sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos); //this converts the window coords, to what the view sees.
					int index = (((int)worldPos.y) / 56) * 8 + ((int)worldPos.x/56); //converts it into an index for the tilemap
					
					if (lastClicked != index && index < 63 && index > -1) {
						if (lastClicked != -1) {
							//tile[index] = tile[lastClicked];
							//tile[lastClicked] = 0;
							//index = -1; 
							//lastClicked = -1;
							if (validMove((PIECES)tile[index], Vector2i(worldPos.y / 56 * 8, worldPos.x / 56), moveMap, tile, oldPos)) {
								tile[index] = tile[lastClicked];
								tile[lastClicked] = 0;
								index = -1; //resetting chosen 
								lastClicked = -1;
							}
						}

						
						
						
					}
					else {
						lastClicked = -1;
					}
					//ADD IN SUPPORT FOR BUTTONS ON SIDE IF IMPLEMENTED
					//std::cout << worldPos.x << ", " << worldPos.y << " index: " << index << " " << index << std::endl; //debug
					
					//TODO getAvailableMoves();
					//TODO showMoves();
					if (index != -1)
					{
						oldPos.x = worldPos.x/56;
						oldPos.y = worldPos.y / 56 * 8;
						lastClicked = index;
						
					}
						
				}

			if (e.type == Event::MouseButtonReleased)
				if (e.key.code == Mouse::Left)
				{
					//isMove = false;
					//Vector2f p = sprites[n].getPosition() + Vector2f(size / 2, size / 2);
					//newPos = Vector2f(size*int(p.x / size), size*int(p.y / size));
					///str = util.convToChessSquare(oldPos,size) + util.convToChessSquare(newPos,size);
					//move(str);
					//if (oldPos != newPos) position += str + " ";
					//sprites[n].setPosition(newPos);
				}
		}

		//comp move
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			str = getNextMove(position);
			//oldPos = util.toCoord(str[0], str[1],size);
			//newPos = util.toCoord(str[2], str[3],size);
			move(str);  
			position += str + " ";
			//sprites[n].setPosition(newPos);
		}

		if (isMove) 
			sprites[n].setPosition(mousePos.x - dx, mousePos.y - dy);

		// draw  
		TileMap b;
		b.load("images/chessboard.jpg", Vector2u(56, 56), board, 8, 8);

		TileMap map;
		map.load("images/figures.png", Vector2u(56, 56), tile, 8, 8);
		window.clear();
		window.setView(view);
		window.draw(b);
		window.draw(map);
		window.display();
	}
	//close stockfish AI connection
	CloseConnection();

	return 0;
}
