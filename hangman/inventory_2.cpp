#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string>inventory;
    inventory.push_back("sword");
    inventory.push_back("armor");
    inventory.push_back("shield");
    cout << "You have "<< inventory.size() << " items.\n";
    for (auto &x: inventory){
        cout << x << endl;
    }
    cout << "\nYou trade your sword for a battle axe.\n";
    inventory[0] = "battle axe";
    cout << "\nYour items:\n";
    for (auto &x: inventory) {
        cout << x << endl;
    }

    cout << "\nThe item name " << inventory[0] << " has ";
    cout << inventory[0].size() << " a letters in it. \n";
    
    cout << "\nYou shield is destroyed in a fierce battle.\n";
    inventory.pop_back();
    cout << "\nYour items:\n";
    for (auto &x: inventory) {
        cout << x << endl;
    }
    cout << "\nYou were robbed of all of your possessions by a thief.\n";
    inventory.clear();
    if (inventory.empty()) {
        cout << "\nYou have nothing!\n";
    } else {
        cout << "\nYou have at least one item.\n";
    }

    return 0;


}