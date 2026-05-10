#include "Board.h"
#include <iostream>
using namespace std;

Board::Board() {
    for (int i = 0; i < 8; i++)

        for (int j = 0; j < 8; j++)
            b[i][j] = nullptr;

}

void Board::setup() {
    for (int j = 0; j < 8; j++) {

        b[1][j] = new Pawn('B');


        b[6][j] = new Pawn('W');
    }
    b[0][0] = new Rook('B'); 

    b[0][7] = new Rook('B');

    b[7][0] = new Rook('W');  
    b[7][7] = new Rook('W');

    b[0][1] = new Knight('B');

    b[0][6] = new Knight('B');

    b[7][1] = new Knight('W');

    b[7][6] =  new Knight('W');

    b[0][2] =   new Bishop('B'); 

    b[0][5] = new Bishop('B');

    b[7][2] = new Bishop('W');

    b[7][5] = new Bishop('W');

    b[0][3] = new Queen('B');

    b[7][3] = new Queen('W');

    b[0][4] = new King('B');

    b[7][4] = new King('W');

}

void Board::display() {
    cout << "  a b c d e f g h"<< endl;
    for (int i = 0; i < 8; i++) {
        cout << 8 - i << " ";
        for (int j = 0; j < 8; j++) {
            if (b[i][j] == nullptr) cout << ". ";
            else cout << b[i][j]->getSymbol() << " ";
        }
        cout << 8 - i << endl;
    }
    cout << "  a b c d e f g h\n";
}