#ifndef PIECE_H
#define PIECE_H

class Piece {
protected:
    char color;

public:
    Piece(char c);
    virtual ~Piece() {}

    virtual bool isWhite() = 0;
    virtual char getSymbol() = 0;

    virtual bool is_valid_move(int sx, int sy, int ex, int ey, Piece* board[8][8]) = 0;
};

#endif