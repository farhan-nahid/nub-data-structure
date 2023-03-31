#include <iostream>
using namespace std;

char board[3][3] = {'1','2','3','4','5','6','7','8','9'};
char player = 'X';
int choice;

void drawBoard()
{
    system("cls");
    cout << "\n\nTic Tac Toe\n\n";
    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
    cout << "     |     |     " << endl << endl;
}

void playerTurn()
{
    if (player == 'X')
        cout << "Player 1 (X) turn: ";
    else
        cout << "Player 2 (O) turn: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            if (board[0][0] == '1')
                board[0][0] = player;
            else
            {
                cout << "Invalid move, try again!\n";
                playerTurn();
            }
            break;
        case 2:
            if (board[0][1] == '2')
                board[0][1] = player;
            else
            {
                cout << "Invalid move, try again!\n";
                playerTurn();
            }
            break;
        case 3:
            if (board[0][2] == '3')
                board[0][2] = player;
            else
            {
                cout << "Invalid move, try again!\n";
                playerTurn();
            }
            break;
        case 4:
            if (board[1][0] == '4')
                board[1][0] = player;
            else
            {
                cout << "Invalid move, try again!\n";
                playerTurn();
            }
            break;
        case 5:
            if (board[1][1] == '5')
                board[1][1] = player;
            else
            {
                cout << "Invalid move, try again!\n";
                playerTurn();
            }
            break;
        case 6:
            if (board[1][2] == '6')
                board[1][2] = player;
            else
            {
                cout << "Invalid move, try again!\n";
                playerTurn();
            }
            break;
        case 7:
            if (board[2][0] == '7')
                board[2][0] = player;
            else
            {
                cout << "Invalid move, try again!\n";
                playerTurn();
            }
            break;
        case 8:
            if (board[2][1] == '8')
               
        board[2][1] = player;
        else
        {
            cout << "Invalid move, try again!\n";
            playerTurn();
        }
        break;
    case 9:
        if (board[2][2] == '9')
            board[2][2] = player;
        else
        {
            cout << "Invalid move, try again!\n";
            playerTurn();
        }
        break;
    default:
        cout << "Invalid move, try again!\n";
        playerTurn();
        break;
}
}

bool gameOver()
{
//check if any row has same element
for (int i = 0; i < 3; i++)
{
if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
return true;
}

//check if any column has same element
for (int i = 0; i < 3; i++)
{
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        return true;
}

//check if any diagonal has same element
if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    return true;

if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    return true;

//check if any element is left
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        if (board[i][j] != 'X' && board[i][j] != 'O')
            return false;
    }
}

//draw
drawBoard();
cout << "Game Over: It's a draw!" << endl;
return true;
}

void changePlayer()
{
if (player == 'X')
player = 'O';
else
player = 'X';
}

int main()
{
cout << "Tic Tac Toe\n";
cout << "Player 1 (X) - Player 2 (O)" << endl << endl;
while (!gameOver())
{
    drawBoard();
    playerTurn();
    gameOver();
    changePlayer();
}

return 0;
