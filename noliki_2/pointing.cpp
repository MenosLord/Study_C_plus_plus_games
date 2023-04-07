#include <iostream>
#include <string>

using namespace std;

int main() {
    int* pScore = 0; // объявляем и инициализируем указатель
    int score = 1000;
    pScore = &score; //присваиваем указателю адрес переменной score
    cout << "Assigning &score to pSore\n";
    cout << "&score is: " << &score << "\n"; // адрес переменной score 
    cout << "pScore is: " << pScore << "\n"; // адрес сохраненный в указателе
    cout << "score is: " << score << "\n";
    cout << "*pScore is: " << *pScore << "\n"; // значение на которое направлен указатель
    cout << "Adding 500 to score\n";
    score += 500;
    cout << "score is: " << score << "\n";
    cout << "*pScore is: " << *pScore << "\n\n";
    cout << "Adding 500 to *pScore\n";
    *pScore += 500;
    cout << "score is: " << score << "\n";
    cout << "*pScore is: " << *pScore << "\n\n";
    cout << "Assigning &newScore to pScore\n";
    int newScore = 5000;
    pScore = &newScore;
    cout << "&newScore is:" << &newScore << "\n";
    cout << "pScore is: " << pScore << "\n";
    cout << "newScore is: " << newScore << "\n";
    cout << "*pScore is: " << *pScore << "\n\n";
    cout << "Assigning &str to pStr\n";
    string str = "score";
    string* pStr = &str; // указатель на строку
    cout << "Str is: " << str << "\n";
    cout << "*pSrt is: " << *pStr << "\n";
    cout << "(*pStr).size() is: " << (*pStr).size() << "\n";
    cout << "pStr->size() is: " << pStr->size() << "\n";
    return 0;
}