#include <iostream>
using namespace std;

//stat of XO and empty in each table
char board[10] = { 'o' , '1' , '2' , '3' ,
                         '4' , '5' , '6' ,
                         '7' , '8' , '9'};


void show_board(){ //show board in terminal
    system("cls"); //clear the terminal but will show again with the updated board
    cout << "\n\n" << "simple XO game made by high-school student" << "\n\n";
    cout << "player 1 (X) -- player 2 (O)" << "\n\n" << endl;

    cout << "   |   |   " << endl;
    cout << " " << board[1] << " | " << board[2] << " | " << board[3] << " " << endl;

    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;

    cout << " " << board[4] << " | " << board[5] << " | " << board[6] << " " << endl;

    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;

    cout << " " << board[7] << " | " << board[8] << " | " << board[9] << " " << endl;

    cout << "   |   |   " << endl;
}


int board_status(){ //check the board status 1 = there is winner ; 0 = the game end ; -1 = game is in progress
    if (board[1] == board[2] && board[2] == board[3]){       // horizontally
        return 1;
    } else if (board[4] == board[5] && board[5] == board[6]){ 
        return 1;
    } else if (board[7] == board[8] && board[8] == board[9]){
        return 1;
    } else if (board[1] == board[4] && board[4] == board[7]){ // vertically
        return 1;
    } else if (board[2] == board[5] && board[5] == board[8]){
        return 1;
    } else if (board[3] == board[6] && board[6] == board[9]){
        return 1;
    } else if (board[1] == board[5] && board[5] == board[9]){ // diagonally
        return 1;
    } else if (board[3] == board[5] && board[5] == board[7]){
        return 1;
    } else if (board[1] != '1' && board[2] != '2' && board[3] != '3' //every board is full but not winnable; therefore the game is finished
               && board[4] != '4' && board[5] != '5' && board[6] != '6'
               && board[7] != '7' && board[8] != '8' && board[9] != '9')
               {
                    return 0 ;
               }
    else { //the condition that the game is not end
        return -1;
    }
}

int main(){
    int player = 1 , choice;
    
    int i; //check state of board

    char mark;
    do {
        show_board();
        player = (player % 2) ? 1 : 2; //player will ++ and %2 (0 and 1 is result) and check with short hand if-else

        cout << "\n\n" << "player " << player << ", enter the number: ";
        cin >> choice;

        mark = (player == 1) ? 'X' : 'O' ; // check if player is 1 the mark will be X if 2 then O
        
        //apply choice to board
        if (choice == 1 && board[1] == '1'){
            board[1] = mark;
        } else if (choice == 2 && board[2] == '2') {
            board[2] = mark;
        } else if (choice == 3 && board[3] == '3') {
            board[3] = mark;
        } else if (choice == 4 && board[4] == '4') {
            board[4] = mark;
        } else if (choice == 5 && board[5] == '5') {
            board[5] = mark;
        } else if (choice == 6 && board[6] == '6') {
            board[6] = mark;
        } else if (choice == 7 && board[7] == '7') {
            board[7] = mark;
        } else if (choice == 8 && board[8] == '8') {
            board[8] = mark;
        } else if (choice == 9 && board[9] == '9') {
            board[9] = mark;
        } else { //if the choice is in the board that already mark then ignore it and input agin
            cout << "INVALID MOVE!";

            player--;
            cin.ignore();
            cin.get();
        }
        
        i = board_status(); //check the board and get i value to make condition
        player++;
    }
    while (i == -1); //the code at the top will run for ever until the game is end (win or draw)
    show_board();
    if (i == 1){
        cout << "player " << --player << " win the game!";
    } else {
        cout << "game draw!";
    }
    cin.ignore();
    cin.get();
    return 0;
}