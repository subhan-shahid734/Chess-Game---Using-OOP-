#include "Bishop.h"
#include <cstdlib>
Bishop::Bishop(char color, int row, int col) : Piece(color, row, col) { // Becaose inheriting from piece, initializer list is necessary
}
char Bishop::get_symbol() {
    return 'B';
}
bool Bishop::is_valid_move(int to_row, int to_col, Piece* board[8][8]) {
    if (abs(to_row - row) != abs(to_col - col)) { // Bishop can move just diagonally
        return false;
    }
    int row_dir;
    int col_dir;
    if (to_row > row) {
        row_dir = 1;
    } else {
        row_dir = -1;
    }
    if (to_col > col) {
        col_dir = 1;
    } else {
        col_dir = -1;
    }
    int r = row + row_dir;
    int c = col + col_dir;
    while (r != to_row && c != to_col) { // go untill the destination square(not included)
        if (board[r][c] != NULL) { // checking whether the whole path is free or captured
            return false;
        }
        r = r + row_dir;
        c = c + col_dir;
    }
    if (board[to_row][to_col] != NULL && board[to_row][to_col]->get_color() == color) { // can't capture our own solider
        return false; // through colour, solider can be recognized
    }
    return true; // means the solider of opponent will be arrested
}
