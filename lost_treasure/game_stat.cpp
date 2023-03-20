#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {
    // int score;
    // double distance;
    // char playAgain;
    // bool shieldsUp;

    // short lives, aliensKilled;

    // score = 0;
    // distance = 1200.76;
    // playAgain = 'y';
    // shieldsUp = true;
    // lives = 3;
    // aliensKilled = 10;

    // double engineTemp = 6572.89;

    // cout << "\nscore: " << score << endl;
    // cout << "distance: " << distance << endl;
    // cout << "playAgain: " << playAgain << endl;
    // cout << "lives: " << lives << endl;
    // cout << "aliensKilled: " << aliensKilled << endl;
    // cout << "engineTemp: " << engineTemp << endl;

    // int fuel;
    // cout << "\nHow much fuel? ";
    // cin >> fuel;
    // cout << "fuel: " << fuel << endl;

    // typedef unsigned short int ushort;
    // ushort bonus = 10;
    // cout << "\nbonus: " << bonus << endl;

    // return 0;

    const int ALIEN_POINTS = 150;
    int aliensKilled = 10;
    int score = aliensKilled * ALIEN_POINTS;
    cout << "score: " << score << endl;
/*
    enum difficulty {NOVICE, EASY, NORMAL, UNBEATABLE};
    difficulty myDifficulty = EASY;
*/
    enum shipCost {FIGHTER_COST = 25, BOMBER_COST, CRUISER_COST = 50};
    shipCost myShipCost = BOMBER_COST;
    cout << "\nTo upgrade my ship to a Cruiser will cost "
         << (CRUISER_COST - myShipCost) << " Resource Points. \n";
    return 0;
    
}