#include "Bishop.h"
#include <cstdlib>

Bishop::Bishop(char c) :Piece(c) {}

bool Bishop::isWhite() { return color == 'W'; }

char Bishop::getSymbol() { return (color == 'W') ? 'B' : 'b'; }

bool Bishop::is_valid_move(int sx, int sy, int ex, int ey, Piece* board[8][8]) {

    if (abs(ex - sx) != abs(ey - sy)) return false;

    int r = (ex > sx) ? 1 : -1;
    int c = (ey > sy) ? 1 : -1;

    int i = sx + r, j = sy + c;

    while (i != ex) {
        if (board[i][j]) return false;
        i += r; j += c;
    }

    if (board[ex][ey] && board[ex][ey]->isWhite() == isWhite())
        return false;

    return true;
}