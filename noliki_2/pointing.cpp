#include <iostream>
#include <string>

using namespace std;

int main() {
    int* pAPointer; //объявялем указатель
    int* pScore = 0; // объявляем и инициализируем указатель
    int score = 1000;
    pScore = &score; //присваиваем указателю адрес переменной score
    cout << "Assigning &score to pSore\n";
    cout << "&score is: " << &score << "\n"; // адрес переменной score 
    cout << "pScore is: " << pScore << "\n"; // адрес сохраненный в указателе
    cout << "score is: " << score << "\n";
    cout << "*pScore is: " << *pScore << "\n"; // значение на которое направлен указатель
    


}