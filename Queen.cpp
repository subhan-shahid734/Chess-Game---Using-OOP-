#include "Queen.h"
#include <cstdlib>

Queen::Queen(char c) :Piece(c) {}

bool Queen::isWhite() { return color == 'W'; }

char Queen::getSymbol() { return (color == 'W') ? 'Q' : 'q'; }

bool Queen::is_valid_move(int sx, int sy, int ex, int ey, Piece* board[8][8]) {

    bool straight = (sx == ex || sy == ey);
    bool diagonal = (abs(ex - sx) == abs(ey - sy));

    if (!straight && !diagonal) return false;

    if (straight) {
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
    }

    if (diagonal) {
        int r = (ex > sx) ? 1 : -1;
        int c = (ey > sy) ? 1 : -1;

        int i = sx + r, j = sy + c;

        while (i != ex) {
            if (board[i][j]) return false;
            i += r; j += c;
        }
    }

    if (board[ex][ey] && board[ex][ey]->isWhite() == isWhite())
        return false;

    return true;
}