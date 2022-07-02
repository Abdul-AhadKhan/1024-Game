#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
void newnum(int game[][4])
{
	int i = 0;
	int j = 0;
	bool check2 = false;
	int num = 0;
	srand(time(0));
	while (!check2)
	{
		i = rand() % 4;
		j = rand() % 4;
		num = (rand() % 3) + 2;
		if (game[i][j] == 0 && num != 3)
		{
			game[i][j] = num;
			check2 = true;
		}
	}
}
void printgrid(int game[][4])
{
	system("cls");
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			if (game[row][col] > 0)
			{
				cout << setw(4) << game[row][col] << "|";
			}
			else
			{
				cout << setw(5) << "|";
			}
		}
		cout << endl;
		cout << "----------------------";
		cout << endl;
	}
}
int rightMove(int game[][4], int no_of_rows)
{
	int i;
	int check = 0;
	int check1 = 0;
	for (int row = 0; row < 4; row++)
	{
		check = 3;
		for (int col = 2; col >= 0; col--)
		{
			if (game[row][col] > 0)
			{
				i = col;
				game[row][i] = game[row][col];
				for (i = col; i < check;i++ )
				{
					if (game[row][i + 1] == 0)
					{
						game[row][i + 1] = game[row][i];
						game[row][i] = 0;
						check1 = 1;
					}
					else if (game[row][i + 1] == game[row][i])
					{
						game[row][i + 1] = game[row][i] + game[row][i + 1];
						game[row][i] = 0;
						check = i;
						check1 = 1;
					}
				}	
			}
		}
	}
	return check1;
}
int leftMove(int game[][4], int no_of_rows)
{
	int i;
	int check = 0;
	int check1 = 0;
	for (int row = 0; row < 4; row++)
	{
		check = 0;
		for (int col = 1; col < 4; col++)
		{
			if (game[row][col] > 0)
			{
				i = col;
				game[row][i] = game[row][col];
				for (; i > check;i--)
				{
					if (game[row][i - 1] == 0)
					{
						game[row][i - 1] = game[row][i];
						game[row][i] = 0;
						check1 = 1;
					}
					else if (game[row][i - 1] == game[row][i] )
					{
						game[row][i - 1] = game[row][i] + game[row][i - 1];
						game[row][i] = 0;
						check = i;
						check1 = 1;
					}
				}
			}
		}
	}
	return check1;
}
int downMove(int game[][4], int no_of_rows)
{
	int i, temp;
	int check = 0;
	int check1 = 0;
	for (int col = 0; col < 4; col++)
	{
		check = 3;
		for (int row = 2; row >= 0; row--)
		{
			if (game[row][col] > 0)
			{
				i = row;
				game[i][col] = game[row][col];
				for (i = row; i < check;i++)
				{
					if (game[i + 1][col] == 0)
					{
						game[i + 1][col] = game[i][col];
						game[i][col] = 0;
						check1 = 1;
					}
					else if (game[i + 1][col] == game[i][col] )
					{
						game[i + 1][col] = game[i][col] + game[i + 1][col];
						game[i][col] = 0;
						check = i;
						check1 = 1;
					}
				}
			}
		}
	}
	return check1;
}
int upMove(int game[][4], int no_of_rows)
{
	int i;
	int check = 0;
	int check1 = 0;
	for (int col = 0; col < 4; col++)
	{
		check = 0;
		for (int row = 1; row < 4; row++)
		{
			if (game[row][col] > 0)
			{
				i = row;
				game[i][col] = game[row][col];
				for (; i > check;i--)
				{
					if (game[i - 1][col] == 0)
					{
						game[i - 1][col] = game[i][col];
						game[i][col] = 0;
						check1 = 1;
					}
					else if (game[i - 1][col] == game[i][col] )
					{
						game[i - 1][col] = game[i][col] + game[i - 1][col];
						game[i][col] = 0;
						check = i;
						check1 = 1;
					}
				}
			}
		}
	}
	return check1;
}
bool spacecheck(int game[][4])
{
	bool check = false;
	for (int row = 0; row < 4 && !check; row++)
	{
		for (int col = 0; col < 4 && !check; col++)
		{
			if (game[row][col] == 0)
			{
				check = true;
			}
		}
	}
	return check;
}
int main()
{
	bool check = false;
	bool check1 = false;
	bool check3 = false;
	int row, col;
	int num = 0;
	char move;
	int game[4][4] = {  };
	newnum(game);
	newnum(game);
	printgrid(game);

	while (!check)
	{
		num = 0;
		cout << "For right press RIGHT Arrow key" << endl;
		cout << "For left press LEFT Arrow Key" << endl;
		cout << "For up press UP Arrow Key" << endl;
		cout << "For Down press DOWN Arrow key" << endl;
		cout << "Press the letter for desired move ";
		switch (move = _getch())
		{
			case KEY_LEFT: num = leftMove(game, 4);
						   break;

			case KEY_RIGHT: num = rightMove(game, 4);
							break;

			case KEY_UP: num = upMove(game, 4);
						 break;

			case KEY_DOWN: num = downMove(game, 4);
						   break;

			default: cout << "Invalid input ";
					 break;
		}
		check1 = spacecheck(game);
		if (check1 && num)
		{
			newnum(game);	
		}
		for (row = 0; row < 4 &&  !check; row++)
		{
			for (col = 0; col < 4 && !check; col++)
			{
				if (game[row][col] == 1024)
				{
					cout << "You Won! " << endl;
					check = true;
				}
			}
		}
		printgrid(game);
		check1 = spacecheck(game);
		if (!check1 )
		{
			check3 = false;
			for (row = 0; row < 4 && !check3; row++)
			{
				for (col = 0; col < 4 && !check3; col++)
				{
					if (row == 0 && col == 0)
					{
						if (game[row][col] == game[row][col + 1] || game[row][col] == game[row + 1][col] )
						{
							check3 = true;
							break;
						}
					}
					else if ((row > 0 && row < 3) && (col == 0) )
					{
						if (game[row][col] == game[row - 1][col] || game[row][col + 1] == game[row][col] || game[row][col] == game[row + 1][col])
						{
							check3 = true;
							break;
						}
					}
					else if (row == 3 && col == 0 )
					{
						if (game[row][col] == game[row][col + 1] || game[row][col] == game[row - 1][col])
						{
							check3 = true;
							break;
						}
					}
					else if (row == 0 && (col > 0 && col < 3) )
					{
						if (game[row][col] == game[row][col + 1] || game[row][col] == game[row][col - 1] || game[row][col] == game[row + 1][col])
						{
							check3 = true;
							break;
						}
					}
					else if ((row > 0 && row < 3) && (col > 0 && col < 3) )
					{
						if (game[row][col] == game[row][col + 1] || game[row][col] == game[row][col - 1] || game[row][col] == game[row - 1][col] || game[row][col] == game[row + 1][col])
						{
							check3 = true;
							break;
						}
					}
					else if (row == 3 && (col > 0 && col < 3) )
					{
						if (game[row][col] == game[row][col + 1] || game[row][col] == game[row][col - 1] || game[row][col] == game[row - 1][col])
						{
							check3 = true;
							break;
						}
					}
					else if (row == 0 && col == 3 )
					{
						if (game[row][col] == game[row][col - 1] || game[row][col] == game[row + 1][col])
						{
							check3 = true;
							break;
						}
					}
					else if ((row > 0 && row < 3) && col == 3)
					{
						if (game[row][col] == game[row][col - 1] || game[row][col] == game[row + 1][col] || game[row][col] == game[row -1][col])
						{
							check3 = true;
							break;
						}
					}
					else if (row == 3 && col == 3)
					{
						if (game[row][col] == game[row][col - 1] || game[row][col] == game[row - 1][col])
						{
							check3 = true;
							break;
						}
					}
				}
			}
			if (!check3)
			{
				cout << "Game Over ! ";
				check = true;
			}
		}
	}
	system("pause");
	return 0;
}