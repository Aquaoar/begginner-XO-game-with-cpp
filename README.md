# begginner-XO-game-with-cpp
The beginner XO game wirte by c++ that make by high-school student. There maybe error or typo in the code.

 I'm not good at grammar and write in code language since I'm not native speaker and I'm newbie about coding but I will try my best to explain how this code work.
 ## 1.state of each element in the board
 ``` cpp
//state of XO and empty in each table 
char board[10] = { 'o' , '1' , '2' , '3' ,
                         '4' , '5' , '6' ,
                         '7' , '8' , '9'};
```
This is the first line of code that come after the header. This code is make a char array name "board". In the array there are 10 elemeent range from o , 1 , 2, ... , 10. (The 'o' is not in use but it there to make it easier to write code.) this number in array use to indicate where to put "mark" and each element can change itself to X or 0 or number(default).
## 2. show board function
``` cpp
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
```

this is function to show the board.
>system("cls")  is to clear the terminal

the first output of this function is the header test of terminal. after that it will be the board with the element of array in each square
<pre>//output of this function (if the board array hasn't change anything)
   |   |
 1 | 2 | 3
___|___|___
   |   |
 4 | 5 | 6
___|___|___
   |   |
 7 | 8 | 9
   |   |
</pre>
if I change board[1] = 'X' the '1' that in the board will change to 'X'
<pre>//output of this function (if the board[1] = 'X')
   |   |
 X | 2 | 3
___|___|___
   |   |
 4 | 5 | 6
___|___|___
   |   |
 7 | 8 | 9
   |   |
</pre>
## 3. board/game status
```cpp
  int board_status(){ //check the board status 1 = there is winner ; 0 = the game end with draw ; -1 = game is in progress
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
```
This function give the state of game by -1 0 1 (-1 = game in progress ; 0 = game is end with draw ; 1 = game is end with win/lose

if the game is finish by win/lose that check by the first eight if-else. It will return 1 (meaning the function board_status() == 1)

if the game is finish by draw that check by ninth if-else (it check that if every square is not deafualt number meaning every square is all mark but there in no win/lose since the first eight if-else is not ture). it will return 0 (board_status() == 0)

if all the if-else is not true at all (meaning the game is in the progress).It will return -1 (board_status() == -1)
## 4. Apply the function
``` cpp
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
        } else { //if the choice is in the board that already mark then ignore it and input again
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
    } else { //i = 0
        cout << "game draw!";
    }
    cin.ignore();
    cin.get();
    return 0;
}
```
this is the main function that will be executed. the first 3 line in this fucntion is to assign a value 
>int player = 1, choice;

player = 1 since the first player is 1 , choice (this stored the input that user input for choice that user choose)

>int i;

is to stored the state of the game in the board_status() function (i = board_status())
>char mark;

is to stored the mark that will be in square

### Next is do/while fuction
``` cpp
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
        } else { //if the choice is in the board that already mark then ignore it and input again
            cout << "INVALID MOVE!";

            player--;
            cin.ignore();
            cin.get();
        }
        
        i = board_status(); //check the board and get i value to make condition
        player++;
    }
    while (i == -1);
```
the code in do{} will be executed first and then check if while condition is true or flase
>while (i == -1);

The do function will be executed until i =! -1 (i not equal to -1) 

---------------------------------------------------------------------

>show_board();

first is show_board() function
>player = (player % 2) ? 1 : 2;

player will increase (at the bottom of do/while function) and %2 (0 and 1 is result. that mean it can be use as true or false) and check with short hand if-else

>cout << "\n\n" << "player " << player << ", enter the number: ";
>
>cin >> choice;

These will make you input the number that you want to mark in board

>mark = (player == 1) ? 'X' : 'O' ;

if player == 1 (the first player's mark is X) then mark will be X. if not then mark will be O

The next will be if else that check if the choice player make is what (so it will know that player want to change that square) and check if that square isn't already change or not
* if both of these is true then it will change board[i] to mark of that player
* if some of these is incorrect (that mean the user input invalid value) then it will output "invalid move" and then ignore and clear that input and restate player to the same player again to reinput

> i = board_status();

This will assign a value i to board_status() (-1 or 0 or 1)

>player++;

this will increase player value in each turn (but it will be 1 or 2 anyway)

------------------------------------

``` cpp
show_board();
if (i == 1){
  cout << "player " << --player << " win the game!";
} else { //i = 0
  cout << "game draw!";
}
```
> show_board();

this will update board to final result

``` cpp
if (i == 1){
  cout << "player " << --player << " win the game!";
} else { //i = 0
  cout << "game draw!";
}
```
this check if i == 1 or i == 0 (i == 1 mean the gane end with win/lose ; i == 0 mean the game end with draw)
*if i == 1 then output the player - 1 win the game (the reason that it need to decrease player value by 1 is that in the do/while loop in the end of it is player++ but if the while is false (the game end) after that the player is offset by 1 so decrease it here to output the correct value
*if i = 0 then output "game draw"

final 3 line is to clear the input and stop the game

# If you are reading all of these. and you spot the mistake you can inform me or smth
### this is my little code project while I'm in high school 
