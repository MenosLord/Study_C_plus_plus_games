#include <iostream>
#include <string>

using namespace std;

int main() {
    const int MAX_ITEMS = 10; //вместимость инвентаря
    string inventory[MAX_ITEMS];
    int numItems=0; //количество вещей, которые несет с собой герой
    inventory[numItems++]="sword";
    inventory[numItems++]="armor";
    inventory[numItems++]="shield";
    cout << "Your items: " << endl;
    for(int i=0; i < numItems; i++) {
        cout << inventory[i] << endl;
    }
    cout << "\nYou trade your sword for a battle axe." << endl;
    inventory[0] = "battle axe";
    cout << "\nYour items: " << endl;
    for(int i=0; i < numItems; i++) {
        cout << inventory[i] << endl;
    }
    cout << "\nThe item name " << inventory[0] << " has ";
    cout << inventory[0].size() << " letters in it." << endl;
    cout << "\nYou find a healing potion.";
    if (numItems < MAX_ITEMS) {
        inventory[numItems++] = "healing potion";
    } else {
        cout << "You have too many items and can't carry another.";
    }
    cout << "\nYour items: " << endl;
    for(int i=0; i < numItems; i++) {
        cout << inventory[i] << endl;
    }
    return 0;

}