#include <iostream>
using namespace std;
char board[9] = {'1', '2', '3', '4', '5','6', '7','8','9'};
char currPlayer = 'X';
char prevPlayer = 'O';
int choice;
bool draw = false;
bool gameOver = false;

void turn(){
    cout <<"\n"<<currPlayer<<"'s turn \n"<<currPlayer<<"'s choice: ";
    cin >> choice;
    bool validChoice = false;
    while (!validChoice){
    if (board[choice - 1] == 'X' || board[choice - 1] == 'O'){
        cout << "Invalid choice. Try again: ";
        cin >> choice;

    } else {
        board[choice - 1] = currPlayer;
        validChoice = true;
    }}
    prevPlayer = currPlayer;

    if (currPlayer == 'X'){
        currPlayer = 'O';
    } else {
        currPlayer = 'X';
    }


}
bool isGameOver(){

    if ((board[0] == board[1] && board[2] == board[0] && board[2] == board[1]) ||  (board[3] == board[4] && board[5] == board[3] && board[5] == board[4]) || (board[6] == board[7] && board[6] == board[8] && board[7] == board[8]) ){
       return true;
    } else if ((board[0] == board[3] && board[3] == board[6] && board[0] == board[6]) || (board[1] == board[4] && board[4] == board[7] && board[1] == board[7]) || (board[2] == board[5] && board[5] == board[8] && board[2] == board[8])){
        return true;
    } else if((board[0] == board[4] && board[4] == board[8] && board[0] == board[8]) || (board[2] == board[4] && board[4] == board[6] && board[2] == board[6])){
        return true;
    }
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            return false;
        }
    }

    draw = true;
    return true;
}
void displayBoard(){
    cout << " " << board[0] << " | "<< board[1] <<" | "<<board[2] <<"\n-----------\n "<<board[3] <<" | "<<board[4] <<" | "<< board[5] <<" \n-----------\n "<< board[6] <<" | "<< board[7] <<" | "<< board[8] <<" \n\n";
}

int main() {
    cout << "Tic Tac Toe \n";

    while (!gameOver){
        displayBoard();
        turn();
        gameOver = isGameOver();
    }
    displayBoard();
    if (draw){
        cout <<"It's a draw!";
    } else{
        cout <<prevPlayer <<" wins!";
    }



    return 0;
}