#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

int main() {
    vector<int>::const_iterator iter;
    cout << "Creating a list of scores.";
    vector <int> scores;
    scores.push_back(1500);
    scores.push_back(3500);
    scores.push_back(7500);
    cout << "\nHigh Scores:\n";
    for (iter = scores.begin(); iter!=scores.end(); ++iter){
        cout << *iter << endl;
    }
    return 0;


}