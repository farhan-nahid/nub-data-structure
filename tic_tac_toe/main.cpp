#include <iostream>

using namespace std;

char turn = 'X', who_win = ' ';
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

    is_success = true;

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



// game over
bool game_over(char board[3][3]){
    for(int i = 0; i < 3; i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i]){  
            return false;
        }
    }

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0]){
        return false;
    }

    // check is all the box is filled?
    int count = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == 'X' || board[i][j] == 'O'){
                count++;
            }
        }
    }
    
    if(count == 9){
        who_win = ' ';
        return false; 
    }
    

  return true;
}



// who win
void who_win_game(char board[3][3]){
    for(int i = 0; i < 3; i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
            who_win = board[i][0];
        }

        if(board[0][i] == board[1][i] && board[0][i] == board[2][i]){
            who_win = board[0][i];
        }
    }


    if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){
        who_win = board[0][0];
    }

    if(board[0][2] == board[1][1] && board[0][2] == board[2][0]){
        who_win = board[0][2];
    }
}

int main(){
    char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};

    while (game_over(board))
    {
        print_board(board);
        decide_player_turn(board);
    }

    if(!game_over(board)){
        who_win_game(board);
        print_board(board);
        if(who_win != ' '){
            cout << "Game Over" << endl;
            cout << "Winner is " << who_win << endl;
        } else {
            cout << "Game is Draw" << endl;
        }
    }
    

    return 0;
}