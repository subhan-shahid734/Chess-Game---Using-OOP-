#include "Queen.h"
#include <cstdlib>
Queen::Queen(char color, int row, int col) : Piece(color, row, col) { // Becaose inheriting from piece, initializer list is necessary
}
char Queen::get_symbol() {
    return 'Q'; // Queen combines the power of rook and bishop
}
bool Queen::is_valid_move(int to_row, int to_col, Piece* board[8][8]) {
    bool straight = (row == to_row || col == to_col); // rook-like movement
    bool diagonal = (abs(to_row - row) == abs(to_col - col)); // bishop-like movement
    if (!straight && !diagonal) { // Queen can only move straight or diagonally
        return false;
    }
    if (straight) {
        if (row == to_row) { // moving horizontally
            int col_dir = (to_col > col) ? 1 : -1;
            for (int c = col + col_dir; c != to_col; c += col_dir) {
            if (board[row][c] != NULL) { // checking whether the whole path is free or captured
                    return false;
                }
            }
          }
        if (col == to_col) { // moving vertically
            int row_dir = (to_row > row) ? 1 : -1;
            for (int r = row + row_dir; r != to_row; r += row_dir) {
                if (board[r][col] != NULL) { // checking whether the whole path is free or captured
                    return false;
              }
            }
         }
        }
    if (diagonal) {
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
    }
    if (board[to_row][to_col] != NULL && board[to_row][to_col]->get_color() == color) { // can't capture our own solider
        return false; // through colour, solider can be recognized
    }
    return true; // means the solider of opponent will be arrested
}
