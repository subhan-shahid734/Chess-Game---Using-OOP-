#include "Knight.h"
#include <cstdlib>

Knight::Knight(char c) :Piece(c) {}

bool Knight::isWhite() { return color == 'W'; }

char Knight::getSymbol() { return (color == 'W') ? 'N' : 'n'; }

bool Knight::is_valid_move(int sx, int sy, int ex, int ey, Piece* board[8][8]) {

    int dr = abs(ex - sx);
    int dc = abs(ey - sy);

    if (!((dr == 2 && dc == 1) || (dr == 1 && dc == 2)))
        return false;

    if (board[ex][ey] && board[ex][ey]->isWhite() == isWhite())
        return false;

    return true;
}