/*
    Напишем небольшой план игры:
    Создать пустое поле для игры в крестики нолики
    Сделать инструкцию к игре
    Определить, кто будет ходить первым
    Отрисовать поле
    Если еще никто не победил и не наступила ничья
    Если сейчас ход пользователя, то получить ход пользователя
    Снова отрисовать поле с учетом хода пользователя
    Иначе
    Вычислить ход компа
    Обновить поле с учетом хода компа
    Отрисовать поле
    Передать ход сопернику
    Конец игры. Поздравить победителя или объявить ничью
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// прототипы функций
void instructions(); // отображает правила игры
char askYesorNot(string question); // задает вопрос ожидая ответ "Да" или "Нет"
int askNumbers(string question, int high, int low =0); // запрашивает число из диапазонаб получает вопрос, малое число или большее
                                                      // возвращает число в диапозоне от low до high
char humanPiece(); //определяет какими фигурами будет ходить пользователь. Возвращает X или O
char opponent(char piece); // ответ компа на ход человека
void displayBoard(const vector<char>& board); // отрисовка поля, получает поле
char winner(const vector<char>& board); // определяет победителя игры. Возвращает либо Х, либо О, либо T(ничья), либо N(еще не определено)
bool isLegal(const vector<char>&board, int move); // проверка на корректность хода
int humanMove(const vector<char>&board, char human); // узнает ход пользователя
int computerMove(vector<char>&board, char computer); // узнает ход компа
void announceWinner(char winner, char computer, char human); // оглашение результа. Победа компа, либо человека, либо ничья


// глобальные константы
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T'; // ничья
const char NO_ONE = 'N'; // продолжение игры


int main() {
    int move;
    const int NUM_SQUARES = 9;
    vector<char> board(NUM_SQUARES, EMPTY);
    instructions();
    char human = humanPiece();
    char computer = opponent(human);
    char turn = X;
    displayBoard(board);
    while (winner(board) == NO_ONE) {
        if (turn == human){
            move = humanMove(board, human);
            board[move] = human;
        } else {
            move = computerMove(board, computer);
            board[move] = computer;
        }
        displayBoard(board);
        turn = opponent(turn);
    }
    announceWinner(winnner(board), computer, human);
    return 0;
}






