#include <iostream>
#include <string>

using namespace std;
char askYesorNo1();
char askYesorNo2(string question);


int main() {
    char answer1 = askYesorNo1();
    cout << "Thanks for answering: " << answer1 << "\n\n";
    char answer2 = askYesorNo2("Do you wish to save the game?");
    cout << "Thanks for answering: " << answer2 << "\n";
    return 0;
}

char askYesorNo1(){
    char response1;
    do{
        cout << "Please enter 'y' or 'n':";
        cin >> response1;

    } while (response1 != 'y' && response1 !='n');
    return response1;
}

char askYesorNo2(string question){
    char response2;
    do{
        cout << question << "(y\n): ";
        cin >> response2;

    } while (response2 != 'y' && response2 != 'n');
    return response2;
}