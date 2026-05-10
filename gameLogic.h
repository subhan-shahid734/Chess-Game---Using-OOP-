#pragma once
#include <iostream>
#include <string>
using namespace std;
class Piece {
public:
	virtual bool isValidMove(int& sx, int& sy, int& ex, int& ey, Piece* board[8][8]) = 0;
	virtual bool isWhite() = 0;
	virtual char getSymbol() = 0;
};
class Game
{
private:
	Piece* board[8][8];
	bool white;
public:
	Game();
	void startGame();
	void input(int& sx, int& sy, int& ex, int& ey);
	bool canMove(int& sx, int& sy, int& ex, int& ey);
	void doMove(int& sx, int& sy, int& ex, int& ey);
	bool isKingInDanger(bool whiteColor);
	bool isMoveSafe(int& sx, int& sy, int& ex, int& ey);
	bool isKingDead(bool whiteColor);
};
