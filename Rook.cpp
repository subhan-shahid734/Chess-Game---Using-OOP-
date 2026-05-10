#include "Rook.h"

Rook::Rook(char c) :Piece(c) {}

bool Rook::isWhite() { return color == 'W'; }

char Rook::getSymbol() { return (color == 'W') ? 'R' : 'r'; }

bool Rook::is_valid_move(int sx, int sy, int ex, int ey, Piece* board[8][8]) {

    if (sx != ex && sy != ey) return false;

    if (sx == ex) {
        int dir = (ey > sy) ? 1 : -1;
        for (int j = sy + dir; j != ey; j += dir)
            if (board[sx][j]) return false;
    }

    if (sy == ey) {
        int dir = (ex > sx) ? 1 : -1;
        for (int i = sx + dir; i != ex; i += dir)
            if (board[i][sy]) return false;
    }

    if (board[ex][ey] && board[ex][ey]->isWhite() == isWhite())
        return false;

    return true;
}