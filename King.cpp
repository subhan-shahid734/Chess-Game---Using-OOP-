#include "King.h"
#include <cstdlib>

King::King(char c) :Piece(c) {}

bool King::isWhite() { return color == 'W'; }

char King::getSymbol() { return (color == 'W') ? 'K' : 'k'; }

bool King::is_valid_move(int sx, int sy, int ex, int ey, Piece* board[8][8]) {

    if (abs(ex - sx) > 1 || abs(ey - sy) > 1)
        return false;

    if (board[ex][ey] && board[ex][ey]->isWhite() == isWhite())
        return false;

    return true;
}