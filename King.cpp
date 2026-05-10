#include "King.h"
#include <cstdlib>
King::King(char color, int row, int col) : Piece(color, row, col) { // Becaose inheriting from piece, initializer list is necessary
}
char King::get_symbol() {
    return 'K';
}
bool King::is_valid_move(int to_row, int to_col, Piece* board[8][8]) {
    if (abs(to_row - row) > 1 || abs(to_col - col) > 1) { // King can only move one step in any direction
        return false;
    }
    if (board[to_row][to_col] != NULL && board[to_row][to_col]->get_color() == color) { // can't capture our own solider
        return false; // through colour, solider can be recognized
    }
    return true; // means the solider of opponent will be arrested
}
