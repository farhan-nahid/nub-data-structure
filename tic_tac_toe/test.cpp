#include <iostream>
using namespace std;

char CharArray[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int check_winner()
{
	if (CharArray[1] == CharArray[2] && CharArray[2] == CharArray[3])

		return 1;
	else if (CharArray[4] == CharArray[5] && CharArray[5] == CharArray[6])

		return 1;
	else if (CharArray[7] == CharArray[8] && CharArray[8] == CharArray[9])

		return 1;
	else if (CharArray[1] == CharArray[4] && CharArray[4] == CharArray[7])

		return 1;
	else if (CharArray[2] == CharArray[5] && CharArray[5] == CharArray[8])

		return 1;
	else if (CharArray[3] == CharArray[6] && CharArray[6] == CharArray[9])

		return 1;
	else if (CharArray[1] == CharArray[5] && CharArray[5] == CharArray[9])

		return 1;
	else if (CharArray[3] == CharArray[5] && CharArray[5] == CharArray[7])

		return 1;
	else if (CharArray[1] != '1' && CharArray[2] != '2' && CharArray[3] != '3' &&
		CharArray[4] != '4' && CharArray[5] != '5' && CharArray[6] != '6' &&
		CharArray[7] != '7' && CharArray[8] != '8' && CharArray[9] != '9')

		return 0;
	else
		return -1;
}


void game_board(string name1, string name2)
{
	// system("cls");
    system("clear");

	cout << "\n==========================";
	cout << "\n\tTic Tac Toe\n";
	cout << "\n==========================\n";


	cout << name1 << "(X)" << "========" << name2 << " (0)\n\n";

	cout << "     ||     ||     " << endl;
	cout << "  " << CharArray[1] << "  ||  " << CharArray[2] << "  ||  " << CharArray[3] << endl;

	cout << "=====||=====||=====" << endl;
	cout << "     ||     ||     " << endl;

	cout << "  " << CharArray[4] << "  ||  " << CharArray[5] << "  ||  " << CharArray[6] << endl;

	cout << "=====||=====||=====" << endl;
	cout << "     ||     ||     " << endl;

	cout << "  " << CharArray[7] << "  ||  " << CharArray[8] << "  ||  " << CharArray[9] << endl;

	cout << "     ||     ||     " << endl << endl;
}



int main()
{
	int gamer = 1, i, choice;
	string name1, name2;

	cout << "Enter First Gamer Name: ";
	cin >> name1;

	cout << "\nEnter Second Gamer Name: ";
	cin >> name2;

	char mark;

	do {
		game_board(name1, name2);
		gamer = (gamer % 2) ? 1 : 2;

		if (gamer == 1)
		{
			cout << name1 << " Your Turn, Enter a Number:  ";
			cin >> choice;
		}
		else
		{
			cout << name2 << " Your Turn, Enter a Number:  ";
			cin >> choice;
		}

		

		mark = (gamer == 1) ? 'X' : '0';

		if (choice == 1 && CharArray[1] == '1')

			CharArray[1] = mark;
		else if (choice == 2 && CharArray[2] == '2')

			CharArray[2] = mark;
		else if (choice == 3 && CharArray[3] == '3')

			CharArray[3] = mark;
		else if (choice == 4 && CharArray[4] == '4')

			CharArray[4] = mark;
		else if (choice == 5 && CharArray[5] == '5')

			CharArray[5] = mark;
		else if (choice == 6 && CharArray[6] == '6')

			CharArray[6] = mark;
		else if (choice == 7 && CharArray[7] == '7')

			CharArray[7] = mark;
		else if (choice == 8 && CharArray[8] == '8')

			CharArray[8] = mark;
		else if (choice == 9 && CharArray[9] == '9')

			CharArray[9] = mark;
		else
		{
			cout << "\nInvalid Choice Try Again ";
			gamer--;
			cin.ignore();
			cin.get();
		}

		i = check_winner();
		gamer++;
	} while (i == -1);
	game_board(name1, name2);
	if (i == 1)
	{
		cout << "\n=============================\n";
		cout << "\a" << name1 << " Is A Winner \n";
		cout << "=============================\n";
	}
	else
	{
		cout << "\n=============================\n";
		cout << "\aGame Is Draw\n";
		cout << "=============================\n";
	}

	cin.ignore();
	cin.get();
	return 0;
}

