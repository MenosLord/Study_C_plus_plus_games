#include <iostream>
#include <string>

using namespace std;

int main() {
    string word_1= "Game";
    string word_2("Over");
    string word_3 = "!";
    string phrase = word_1 + " " + word_2 + word_3;
    cout << "The phrase is: " << phrase << endl << endl;
    cout << "The phrase has " << phrase.size() << " character's in it." << endl << endl;
    cout << "The character at position 0 is: " << phrase[0] << endl << endl;
    cout << "Changing the character at position 0." << endl;
    phrase[0] = 'L';
    cout << "The phrase is now: " << phrase << endl << endl;
    for (unsigned int i = 0; i < phrase.size(); ++i) {
        cout << "Character at position " << i << " is: " << phrase[i] << endl;
    }
    cout << "\nThe sequence 'Over' begins at location ";
    cout << phrase.find("Over") << endl;
    if (phrase.find("eggplant") == string::npos) {
        cout << "'eggplant' is not in thr phrase." << endl << endl;
    }
    phrase.erase(4, 5);
    cout << "The phrase is now: " << phrase << endl;
    phrase.erase(4);
    cout << "The phrase is now: " << phrase << endl;
    phrase.erase();
    cout << "The phrase is now: " << phrase << endl;
    if (phrase.empty()) {
        cout << "The phrase is no more." <<endl;
    }
    return 0;

}