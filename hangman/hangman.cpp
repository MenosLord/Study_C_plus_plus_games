#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <string>

using namespace std;

int main() {
    //инициализация переменных

    const int MAX_WRONG = 8; //максимально допустимое число ошибок
    vector<string> words; //подборка загадываемых слов
    words.push_back("GUESS");
    words.push_back("HANGMAN");
    words.push_back("DIFFICULT");
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());
    const string THE_WORD = words[0]; //слово для отгадывания
    int wrong = 0; //количество ошибочных вариантов
    string soFar(THE_WORD.size(), '-'); //часть слова открытая на данный момент
    string used = ""; //уже отгаданные буквы
    cout << "Welcome to Hangman. Good Luck!\n";

    //основной цикл
    while((wrong < MAX_WRONG) && (soFar != THE_WORD)){
        cout << "You have " << (MAX_WRONG-wrong);
        cout << " incorrect guesses left.\n";
        cout << "\nYou've used the following letters:\n" << used << endl;
        cout << "\nSo far, the word is: \n" << soFar << endl;

        //Ввод пользователя 
        char guess;
        cout << "\nEnter your guess: ";
        cin >> guess;
        guess = toupper(guess); // перевод в верхний регистр
        //так как загаданное слово записано в верхнем регистре
        while (used.find(guess) != string::npos){
            cout << "\nYou have already guessed " << guess << endl;
            cout << "\nEnter your guess: ";
            cin >> guess;
            guess = toupper(guess);
        }
        used += guess;
        if (THE_WORD.find(guess) != string::npos){
            cout << "That's right " << guess << " is in the word.\n";
            //обновить переменнную soFar включив в нее новую угаданную букву
            for (unsigned int i =0; i < (THE_WORD.length()); ++i){
                if(THE_WORD[i] == guess){
                    soFar[i]=guess;
                }
            }
        } else {
            cout << "Sorry " << guess << " isn't in the word.\n";
            ++wrong;
        }
    }
    //Окончание игры
    if (wrong == MAX_WRONG){
        cout << "\nYou have been hanged!";
    } else {
        cout << "\nYou guessed it!";
    }
    cout << "\nThe word was " << THE_WORD << endl;
    return 0;
}