#include <iostream>
#include <string>
#include <vector>


using namespace std;

string& ref_to_elemen(vector<string>& vec, int i);

int main() {
    vector<string> inventory;
    inventory.push_back("sword");
    inventory.push_back("armor");
    inventory.push_back("shield");
    // отображение строки, на которую указывает возвращенная ссылка
    cout << "Sending the returned reference to cout: \n";
    cout << ref_to_elemen(inventory, 0) << "\n\n";
    // присваивает одну ссылку другой - малозатратная операция присваивания 
    cout << "Assigning the returned reference to another reference. \n";
    string& rStr = ref_to_elemen(inventory, 1);
    cout << "Sending the new reference to cout: \n";
    cout << rStr << "\n\n";
    //копирование строкового объекта - уже более затратная операция
    cout << "Assigning the returned reference to a string obfject.\n";
    string str = ref_to_elemen(inventory, 2);
    cout << "Sending the new string object to cout: \n";
    cout << str << "\n\n";
    // изменение строкового объекта используя возвращенную ссылку
    cout << "Altering an object through a returned reference. \n";
    rStr = "Healing Potion";
    cout << "Sending the altered object to cout: \n";
    cout << inventory[1] << "\n";
    return 0;
}


// возвращает ссылку на строку
string& ref_to_elemen(vector<string>& vec, int i){
    return vec[i];
}