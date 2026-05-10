#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"

class Queen : public Piece {
public:
    Queen(char c);

    bool isWhite() override;
    char getSymbol() override;
    bool is_valid_move(int sx, int sy, int ex, int ey, Piece* board[8][8]) override;
};

#endif
