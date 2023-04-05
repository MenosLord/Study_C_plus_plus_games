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
int askNumber(string question, int high, int low = 0); // запрашивает число из диапазона получает вопрос, малое число или больше 
                                                      //возвращает число в диапозоне от low до high
char humanPiece(); //определяет какими фигурами будет ходить пользователь. Возвращает X или O
char opponent(char piece); // ответ компа на ход человека
void displayBoard(const vector<char>& board); // отрисовка поля, получает поле
char winner(const vector<char>& board); // определяет победителя игры. Возвращает либо Х, либо О, либо T(ничья), либо N(еще не определено)
bool isLegal(int move,const vector<char>&board); // проверка на корректность хода
int humanMove(const vector<char>&board, char human); // узнает ход пользователя
int computerMove(vector<char> board, char computer); // узнает ход компа
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
    announceWinner(winner(board), computer, human);
    return 0;
}

void instructions(){
    cout << "Welcome to the ultimate man-machine showdown: Tic-Tac-Toe.\n";
    cout << "--where human brain is pit against silicon processor\n\n";

    cout << "Make your move known by entering a number, 0 - 8.  The number\n";
    cout << "corresponds to the desired board position, as illustrated:\n\n";
    
    cout << "0 | 1 | 2\n";
    cout << "---------\n";
    cout << "3 | 4 | 5\n";
    cout << "---------\n";
    cout << "6 | 7 | 8\n\n";

    cout << "Prepare yourself, human.  The battle is about to begin.\n\n";
}

char askYesorNot(string question){
    char response;
    do {
        cout << question << "(y/n): ";
        cin >> response;
    } while(response != 'y' && response != 'n');
    return response;
}

int askNumber(string question, int high, int low){
    int number;
    do {
        cout << question << " (" << low << " - " << high << "): ";
        cin >> number;
    } while(number > high || number < low);
    return number;
}

char humanPiece(){
    char go_first = askYesorNot("Do you require the first move?");
    if (go_first == 'y'){
        cout << "\nThen take the first move. You will need it. \n";
        return X;
    } else {
        cout << "You bravery will be your undoing... I will go first.\n";
        return 0;
    }
}

char opponent(char piece){
    if (piece == X){
        return 0;
    } else {
        return X;
    }
}

void displayBoard(const vector<char>& board){
    cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
    cout << "\n\t" << "---------";
    cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
    cout << "\n\t" << "---------";
    cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
    cout << "\n\n";
}

char winner(const vector<char>& board){
    // перечисляем выигрышные комбинации
    const int WINNING_ROWS[8][3] = { {0, 1, 2},
                                     {3, 4, 5},
                                     {6, 7, 8},
                                     {0, 3, 6},
                                     {1, 4, 7},
                                     {2, 5, 8},
                                     {0, 4, 8},
                                     {2, 4, 6} };
    const int TOTAL_ROWS = 8;
    // если в одном из выигрышных рядов уже есть три одинак-х значения (и они != EMPTY), то победитель определился
    for(int row = 0; row < TOTAL_ROWS; ++row)
    {
        if ( (board[WINNING_ROWS[row][0]] != EMPTY) &&
             (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) &&
             (board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]) )
        {
            return board[WINNING_ROWS[row][0]];
        }
    }

    // так как победителя еще нет, проверяем на ничью
    if (count(board.begin(), board.end(), EMPTY) == 0) {
        return TIE;
    }

    return NO_ONE;
}

inline bool isLegal(int move, const vector<char>&board){
    return (board[move] == EMPTY);
}

int humanMove(const vector<char>&board, char human){
    int move = askNumber("Where will you move?", (board.size() - 1));
    while (!isLegal(move, board)){
        cout << "\nThat square is already occupied, foolish human. \n";
        move = askNumber("Where will you move?", (board.size() - 1));
    }
    cout << "Fine...\n";

    return move;
}

int computerMove(vector<char> board, char computer){
    unsigned int move = 0;
    bool found = false;
    // если комп может выиграть следующим ходом он делает этот ход
    while (!found && move < board.size()){
        if (isLegal(move, board)){
            board[move] = computer;
            found = winner(board) == computer;
            board[move] = EMPTY;
        }
        if (!found) {
            ++move;
        }
    }
    // если человек может победить след. ходом, блокировать этот ход
    if (!found) {
        move = 0;
        char human = opponent(computer);
        while (!found && move < board.size()) {
            if (isLegal(move, board)) {
                board[move] = human;  
                found = winner(board) == human;
                board[move] = EMPTY;        
            }
            if (!found) {
                ++move;
            }
        }
    }
    // или занять следующим ходом оптимальную свободную клетку
    if (!found) {
        move = 0;
        unsigned int i = 0;

        const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};
        // выбрать оптимальную свободную клетку
        while (!found && i <  board.size()) {
            move = BEST_MOVES[i];
            if (isLegal(move, board)) {
                found = true;
            }
            ++i;
        }
    }

    cout << "I shall take square number " << move << endl;
	return move;
}

void announceWinner(char winner, char computer, char human){
    if (winner == computer)
    {
        cout << winner << "'s won!\n";
        cout << "As I predicted, human, I am triumphant once more -- proof\n";
        cout << "that computers are superior to humans in all regards.\n";
    }

	else if (winner == human)
    {
        cout << winner << "'s won!\n";
        cout << "No, no!  It cannot be!  Somehow you tricked me, human.\n";
        cout << "But never again!  I, the computer, so swear it!\n";
    }

	else
    {
        cout << "It's a tie.\n";
        cout << "You were most lucky, human, and somehow managed to tie me.\n";
        cout << "Celebrate... for this is the best you will ever achieve.\n";
	}
}