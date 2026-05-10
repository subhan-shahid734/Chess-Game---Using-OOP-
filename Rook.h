#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"

class Rook : public Piece {
public:
    Rook(char c);

    bool isWhite() override;
    char getSymbol() override;
    bool is_valid_move(int sx, int sy, int ex, int ey, Piece* board[8][8]) override;
};

#endif