#include "Pawn.h"
#include <cstdlib>

Pawn::Pawn(char c) :Piece(c) {}

bool Pawn::isWhite() { return color == 'W'; }

char Pawn::getSymbol() { return (color == 'W') ? 'P' : 'p'; }

bool Pawn::is_valid_move(int sx, int sy, int ex, int ey, Piece* board[8][8]) {

    int dir = (color == 'W') ? -1 : 1;
    int start = (color == 'W') ? 6 : 1;

    if (sy == ey && ex == sx + dir && board[ex][ey] == nullptr)
        return true;

    if (sy == ey && sx == start && ex == sx + 2 * dir &&
        board[sx + dir][sy] == nullptr && board[ex][ey] == nullptr)
        return true;

    if (abs(ey - sy) == 1 && ex == sx + dir &&
        board[ex][ey] && board[ex][ey]->isWhite() != isWhite())
        return true;

    return false;
}