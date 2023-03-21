#include <iostream>
#include <cstring>

using namespace std;

int main() {
    const int ROWS = 3;
    const int COLLUMNS = 3;
    char board[ROWS][COLLUMNS] = {{'O', 'X', 'O'}, {' ', 'X', 'X'}, {'X', 'O', 'O'}};
    cout << "Here's the tic-tac-tae board: " << endl;
    for (int i = 0; i < ROWS; ++i){
        for (int j = 0; j < COLLUMNS; ++j){
            cout << board[i][j];
        }
        cout << endl;
    }

    cout << "\n'X' moves to the empty location." << endl << endl;
    board[1][0]='X';
    cout << "Now the tic-tac-tae board is: " << endl;
    for (int i = 0; i < ROWS; ++i){
        for (int j = 0; j < COLLUMNS; ++j){
            cout << board[i][j];
        }
        cout << endl;
    }
    cout << "\n'X' wins!" << endl;
    return 0;


}