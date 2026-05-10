#include "Game.h"
#include <iostream>
using namespace std;

Game::Game() {
    whiteTurn = true;
    board.setup();
}
//input ftn
void Game::input(int& sx, int& sy, int& ex, int& ey) {

    string from, to;
    cin >> from >> to;

    sy = from[0] - 'a';
    sx = 8 - (from[1] - '0');

    ey = to[0] - 'a';
    ex = 8 - (to[1] - '0');
}
//move validity
bool Game::canMove(int sx, int sy, int ex, int ey) {

    if (sx < 0 || sx>7 || sy < 0 || sy>7 || ex < 0 || ex>7 || ey < 0 || ey>7)
        return false;

    if (!board.b[sx][sy]) return false;

    if (board.b[sx][sy]->isWhite() != whiteTurn)
        return false;

    if (board.b[ex][ey] && board.b[ex][ey]->isWhite() == whiteTurn)
        return false;

    return true;
}
//move execute
void Game::makeMove(int sx, int sy, int ex, int ey) {

    delete board.b[ex][ey];

    board.b[ex][ey] = board.b[sx][sy];
    board.b[sx][sy] = nullptr;

    whiteTurn = !whiteTurn;
}
//king checkmate
bool Game::isKingSafe(bool color) {
    int kx = -1, ky = -1;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board.b[i][j] &&
                board.b[i][j]->isWhite() == color &&
                board.b[i][j]->getSymbol() == (color ? 'K' : 'k')) {
                kx = i;
                ky = j;
            }
        }
    }
    if (kx == -1) return false;  // king not found, treat as unsafe
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board.b[i][j] &&
                board.b[i][j]->isWhite() != color) {
                if (board.b[i][j]->is_valid_move(i, j, kx, ky, board.b))
                    return false;
            }
        }
    }
    return true;
}
bool Game::isCheckmate(bool color) {
    if (isKingSafe(color)) return false;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board.b[i][j] && board.b[i][j]->isWhite() == color) {
                for (int x = 0; x < 8; x++) {
                    for (int y = 0; y < 8; y++) {
                        if (board.b[x][y] && board.b[x][y]->isWhite() == color) continue;
                        if (board.b[i][j]->is_valid_move(i, j, x, y, board.b)) {
                            Piece* moved = board.b[i][j];
                            Piece* target = board.b[x][y];
                            board.b[x][y] = moved;
                            board.b[i][j] = nullptr;
                            bool safe = isKingSafe(color);
                            board.b[i][j] = moved;
                            board.b[x][y] = target;
                            if (safe) return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}
void Game::showTurnMessage() {

    cout << "\n=================================\n";

    if (whiteTurn)
        cout << "WHITE TURN\n";
    else
        cout << "BLACK TURN\n";

    cout << "Enter move like: e2 e4\n";
    cout << "=================================\n";
}

void Game::start() {
    while (true) {
        board.display();
        showTurnMessage();
        int sx, sy, ex, ey;
        input(sx, sy, ex, ey);
        if (!canMove(sx, sy, ex, ey)) {
            cout << "Invalid Move\n";
            continue;
        }
        if (!board.b[sx][sy]->is_valid_move(sx, sy, ex, ey, board.b)) {
            cout << "Illegal Move\n";
            continue;
        }
        makeMove(sx, sy, ex, ey);
        bool opponent = !whiteTurn;
        if (!isKingSafe(opponent) && isCheckmate(opponent)) {
            board.display();
            cout << "CHECKMATE!\n";
            cout << (opponent ? "White" : "Black") << " Wins!\n";
            break;
        }
        if (!isKingSafe(opponent)) {
            cout << "CHECK!\n";
        }
    }
}