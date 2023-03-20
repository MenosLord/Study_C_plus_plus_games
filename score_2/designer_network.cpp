#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    string username;
    string password;
    bool success;
    cout << "Game Designer's Network" << endl;
    do {
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        if (username == "S.Meier" && password == "civilization") {
            cout << "Hey, Sid!" << endl;
            success = true;
        }
        else if (username == "S. Miyamoto" && password == "mariobros") {
            cout <<  "What's up, Shigeru?" << endl;
            success = true;

        }
        else if (username == "W. Wright" && password == "thesims") {
            cout <<  "How goes it, Will?" << endl;
            success = true;
            
        }
        else if (username == "guest" && password == "guest") {
            cout <<  "Welcome, guest!" << endl;
            success = true;
            
        }
        else {
            cout << "Your login failed." << endl;
            success = false;
        } 

    } while(!success);
    return 0;
}