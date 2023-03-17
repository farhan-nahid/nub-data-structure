#include <iostream>

using namespace std;

char turn = 'X';
bool is_success = true;



// print error message
void error_message(){
    system("clear");
    cout << "Invalid Choice ! " << endl; 
    cout << "Please Try again !!! " << endl;
    is_success = false;
    return;
}



// print the board
void print_board(char board[3][3]){
    if(is_success){
        system("clear");
    }
    string player1 = "Player 1 [X]", player2 = "Player 2 [O]";
    
    cout << "\t\t\t\tTic Tac Toe Game" << endl;
    cout << player1 << endl;
    cout << player2 << endl << endl;

    cout << "     " << '|' << "     " << '|' << "     " << endl;
    cout << "  "<< board[0][0] <<"  " << '|' << "  "<< board[0][1] <<"  " << '|' << "  "<< board[0][2] <<"  " << endl;
    cout << "_____" << '|' << "_____" << '|' << "_____" << endl;
    cout << "     " << '|' << "     " << '|' << "     " << endl;
    cout << "  "<< board[1][0] <<"  " << '|' << "  "<< board[1][1] <<"  " << '|' << "  "<< board[1][2] <<"  " << endl;
    cout << "_____" << '|' << "_____" << '|' << "_____" << endl;
    cout << "     " << '|' << "     " << '|' << "     " << endl;
    cout << "  "<< board[2][0] <<"  " << '|' << "  "<< board[2][1] <<"  " << '|' << "  "<< board[2][2] <<"  " << endl;
    cout << "     " << '|' << "     " << '|' << "     " << endl;
}



// decide with player will turn next
void decide_player_turn(char board[3][3]){
    string player1 = "Player 1 [X]", player2 = "Player 2 [O]";
   
    int choice, row, column;

    if(turn == 'X') {
        cout << player1 << " turn ";
    } else {
        cout << player2 << " turn ";  
    }

  
    cin >> choice;

    switch (choice) {
        case 1:
            row = 0;
            column = 0;
            break;
        case 2:
            row = 0;
            column = 1;
            break;
        case 3:
            row = 0;
            column = 2;
            break;
        case 4:
            row = 1;
            column = 0;
            break;
        case 5:
            row = 1;
            column = 1;
            break;
        case 6:
            row = 1;
            column = 2;
            break;

        case 7:
            row = 2;
            column = 0;
            break;
        case 8:
            row = 2;
            column = 1;
            break;
        case 9:
            row = 2;
            column = 2;
            break;
      
        default:
            cout << "Invalid Choice" << endl;
            is_success = false;
            break;
    }

    if(!is_success){
      return error_message();
    }
    
    if(turn == 'X' && (board[row][column] != 'X' && board[row][column] != 'O')) {
        board[row][column] = 'X';
        cout << "Hit" << endl;
        turn = 'O';
        is_success = true;
    } else if(turn == 'O' && (board[row][column] != 'X' && board[row][column] != 'O')) {
        board[row][column] = 'O';
        turn = 'X';
        is_success = true;
    } else {
        error_message();
    }
}


int main(){
    char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};

    while (true)
    {
        print_board(board);
        decide_player_turn(board);
    }
    

    return 0;
}