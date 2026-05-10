#include "Pawn.h"
#include <cstdlib>
Pawn::Pawn(char color, int row, int col) : Piece(color, row, col) { // Becaose inheriting from piece, initializer list is necessary
}
char Pawn::get_symbol() {
    return 'P';
}
bool Pawn::is_valid_move(int to_row, int to_col, Piece* board[8][8]) {
    int dir;
    int start_row;
    if (color == 'W') {
        dir = -1; // white moves upwward
        start_row = 6;
    } else {
        dir = 1; // black moves downwward
        start_row = 1;
    }
    if (to_col == col && to_row == row + dir) {
        if (board[to_row][to_col] != NULL) { // Pawn cannoot capture forward
            return false;
        }
        return true;
    }
    if (to_col == col && row == start_row && to_row == row + 2 * dir) { // two steps only from starting row
        if (board[row + dir][col] != NULL) {
            return false;
        }
        if (board[to_row][to_col] != NULL) {
            return false;
        }
        return true;
    }
    if (abs(to_col - col) == 1 && to_row == row + dir) {
        if (board[to_row][to_col] != NULL && board[to_row][to_col]->get_color() != color) { // enimy must be present to capture diagonaly
            return true;
        }
        return false;
    }
    return false;
}
