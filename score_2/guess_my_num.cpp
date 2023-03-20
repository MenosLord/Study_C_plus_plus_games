#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cin;
using std::endl;
using std::cout;


int main() {
    srand(static_cast<unsigned int>(time(0)));
    int secretNumber = rand() % 100 +1;
    int tries = 0;
    int guess = 0;
    cout << "\tWelcome to Guess My Number!\n\n";
    do{
        cout << "Choose your number: ";
        cin >> guess;
        ++tries;
        if(guess > secretNumber) {
            cout << "Too high" << endl;
        }
        else if (guess < secretNumber) {
            cout << "Too high" << endl;
        }
        else {
            cout << "Yes! It is!" << endl;
        }

    } while(guess != secretNumber);

    return 0;
}