#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cin;
using std::endl;
using std::cout;

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int randomNumber = rand();
    int die = (randomNumber%6) +1; //получаем число от 1 до 6
    cout << "You rolled a " << die << endl;
    return 0;


}