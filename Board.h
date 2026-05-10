#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

class Board {
public:
    Piece* b[8][8];

    Board();
    void setup();
    void display();
};

#endif