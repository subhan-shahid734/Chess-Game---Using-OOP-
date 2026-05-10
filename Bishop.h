#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(char c);

    bool isWhite() override;
    char getSymbol() override;
    bool is_valid_move(int sx, int sy, int ex, int ey, Piece* board[8][8]) override;
};

#endif