#include "Rook.h"
#include <cstdlib>
Rook::Rook(char color, int row, int col) : Piece(color, row, col) { // Becaose inheriting from piece, initializer list is necessary
}
char Rook::get_symbol() {
    return 'R'; // Rook moves straight only
}
bool Rook::is_valid_move(int to_row, int to_col, Piece* board[8][8]) {
    if (row != to_row && col != to_col) { // Rook can only move straight, not diagonally
        return false;
    }
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
    if (board[to_row][to_col] != NULL && board[to_row][to_col]->get_color() == color) { // can't capture our own solider
        return false; // through colour, solider can be recognized
    }
    return true; // means the solider of opponent will be arrested
}
