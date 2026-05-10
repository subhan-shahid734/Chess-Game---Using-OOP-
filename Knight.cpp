#include "Knight.h"
#include <cstdlib>
Knight::Knight(char color, int row, int col) : Piece(color, row, col) { // Becaose inheriting from piece, initializer list is necessary
}
char Knight::get_symbol() {
    return 'N'; // N is used becuase K is taken by King
}
bool Knight::is_valid_move(int to_row, int to_col, Piece* board[8][8]) {
    int row_diff = abs(to_row - row);
    int col_diff = abs(to_col - col);
    if (!((row_diff == 2 && col_diff == 1) || (row_diff == 1 && col_diff == 2))) { // Knigt moves in L shape only
        return false;
    }
    if (board[to_row][to_col] != NULL && board[to_row][to_col]->get_color() == color) { // can't capture our own solider
        return false; // through colour, solider can be recognized
    }
    return true; // means the solider of opponent will be arrested
}
