#ifndef KING_H
#define KING_H
#include "Piece.h"

class King : public Piece {
public:
    King(char c);

    bool isWhite() override;
    char getSymbol() override;
    bool is_valid_move(int sx, int sy, int ex, int ey, Piece* board[8][8]) override;
};

#endif