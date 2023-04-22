#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <Windows.h>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <conio.h>
#include <ctime>
using namespace std;




void setColor(string color)
{
	HANDLE col;
	col = GetStdHandle(STD_OUTPUT_HANDLE);
	int col_code = 7;
	if (color == "blue")
	{
		col_code = 1;
	}
	else if (color == "green")
	{
		col_code = 2;
	}
	else if (color == "cyan")
	{
		col_code = 3;
	}
	else if (color == "red")
	{
		col_code = 4;
	}
	else if (color == "purple")
	{
		col_code = 5;
	}
	else if (color == "darkYellow")
	{
		col_code = 6;
	}
	else if (color == "white")
	{
		col_code = 7;
	}
	else if (color == "grey")
	{
		col_code = 8;
	}
	else if (color == "brightBlue")
	{
		col_code = 9;
	}
	else if (color == "brightGreen")
	{
		col_code = 10;
	}
	else if (color == "brightCyan")
	{
		col_code = 11;
	}
	else if (color == "brightRed")
	{
		col_code = 12;
	}
	else if (color == "pink")
	{
		col_code = 13;
	}
	else if (color == "yellow")
	{
		col_code = 14;
	}
	else if (color == "brightWhite")
	{
		col_code = 15;
	}
	else
	{
		col_code = 7;
	}
	SetConsoleTextAttribute(col, col_code);
}

bool isWinner(vector<vector<char>>& board)
{
	// Check rows
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-')
		{
			return true;
		}
	}

	// Check columns
	for (int j = 0; j < 3; j++) {
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != '-')
		{
			return true;
		}
	}

	// Check diagonals
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-')
	{
		return true;
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-')
	{
		return true;
	}

	// No winner found
	return false;
}