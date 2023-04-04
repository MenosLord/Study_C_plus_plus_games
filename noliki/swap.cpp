#include <iostream>

using namespace std;

void badSwap(int x, int y);
void goodSwap(int& x, int& y);

int main() {
        int myScore = 150;
        int youScore = 1000;
        cout << "Original values: \n";
        cout << "myScore: " << myScore << "\n";
        cout << "youScore: " << youScore << "\n\n";
        cout << "Calling badSwap()\n";
        badSwap(myScore, youScore);
        cout << "myScore: " << myScore << "\n";
        cout << "youScore: " << youScore << "\n\n";
        cout << "Calling goodSwap()\n";
        goodSwap(myScore, youScore);
        cout << "myScore: " << myScore << "\n";
        cout << "youScore: " << youScore << "\n\n";
        return 0;
}



void badSwap(int x, int y){
    int temp = x;
    x = y;
    y = temp;
}
void goodSwap(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}