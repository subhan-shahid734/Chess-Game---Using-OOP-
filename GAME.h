#ifndef GAME_H
#define GAME_H

#include "Board.h"

class Game {
private:
    Board board;
    bool whiteTurn;

public:
    Game();

    void start();
    void input(int& sx, int& sy, int& ex, int& ey);

    bool canMove(int sx, int sy, int ex, int ey);
    void makeMove(int sx, int sy, int ex, int ey);

    bool isKingSafe(bool color);
    bool isCheckmate(bool color);
    void showTurnMessage();
};

#endif