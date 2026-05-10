#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn(char c);

    bool isWhite() override;
    char getSymbol() override;
    bool is_valid_move(int sx, int sy, int ex, int ey, Piece* board[8][8]) override;
};

#endif