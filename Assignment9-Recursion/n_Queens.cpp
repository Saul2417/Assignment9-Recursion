#include "n_Queens.h"
#include <iostream>
#include <string>
#include <cmath>
#include "input.h"

bool checkIfConflict(int boardSize, stack<BoardSpaces> filledSpaces, BoardSpaces currentSpace);

n_Queens::n_Queens()
{
	shiftDirection = 'R';
	firstColumnPermutaions = 0;
	boardSize = 0;
	filled = 0;
	gameWon = false;
}

void n_Queens::setBoardSize(int newBoardSize)
{
	boardSize = newBoardSize;
}

void n_Queens::setFilled(int newFilledAmount)
{
	filled = newFilledAmount;
}

int n_Queens::getBoardSize() const
{
	return boardSize;
}

int n_Queens::getFilled() const
{
	return filled;
}

void n_Queens::placeFirstQueen()
{
	system("cls");
	BoardSpaces currentSpace;
	bool queenConflict = false;
	boardSize = inputInteger("Enter a number(1..100) of queens: ", 1, 100);
	int numQueens = 1;
	int column;
	column = inputInteger("Enter the column to place the first queen : ", 1, boardSize);
	currentSpace.setColumn(column);
	currentSpace.setRow(1);
	filledSpaces.push(currentSpace);
	bool completeBoard = false;
	if (placeQueen(2, column))
	{
		cout << "No Solution Found";
	}

}

bool n_Queens::placeQueen(int numQueens, int column) //something like this will be the main recursive function
{
	////plan:
	//BoardSpaces currentSpace;
	//bool placed = false;
	//bool completeBoard = false;
	//currentSpace.setColumn(column);
	//currentSpace.setRow(numQueens);
	//bool conflict = checkIfConflict(boardSize, filledSpaces, currentSpace);
	//if (numQueens == boardSize && conflict == false) // checks if board is complete
	//{
	//	filledSpaces.push(currentSpace);
	//	displayBoard(filledSpaces);
	//	completeBoard == true;
	//	return completeBoard;
	//}
	//else if (conflict == false)
	//{
	//	filledSpaces.push(currentSpace);
	//}

	//plan:
	BoardSpaces currentSpace;
	bool placed = false;
	bool completeBoard = false;
	currentSpace.setColumn(column);
	currentSpace.setRow(numQueens);

	if (filledSpaces.size() == boardSize) // checks if board is complete
	{		
		displayBoard(filledSpaces);
		completeBoard == true;
		return completeBoard;
	}

	for (int index = 1; index <= boardSize; index++) 
	{
		currentSpace.setColumn(index);
		if (checkIfConflict(boardSize, filledSpaces, currentSpace) == false) 
		{
			// push queen to board
			filledSpaces.push(currentSpace);

			// call the function again
			filled = placeQueen(numQueens + 1, column);

			// Backtrack if needed
			filledSpaces.pop();
		}
	}
	if (filledSpaces.size() == boardSize)
	{
		completeBoard = true;
	}
	return completeBoard;
}

void n_Queens::displayBoard(stack<BoardSpaces> filledSpaces) const
{
	cout << endl << "\t" << boardSize << "-Queens Solution." << endl;
	cout << "\t" << std::string(1, char(201));
	cout << string(boardSize * 2 + 1, char(205));
	cout << string(1, char(187)) << endl;

	for (int index = 0; index < boardSize; index++)
	{
		cout << "\t" << string(1, char(186)) << " ";
		for (int j = 0; j < boardSize; j++)
		{
			if (filledSpaces.top().getColumn() == (j + 1))
			{
				cout << 'Q';
			}
			else
			{
				cout << '-';
			}
			if (j < boardSize - 1)
			{
				cout << string(1, char(179));
			}
		}
		cout << " " << string(1, char(186)) << endl;
		filledSpaces.pop();
	}

	cout << "\t" << std::string(1, char(200));
	cout << string(boardSize * 2 + 1, char(205));
	cout << string(1, char(188)) << endl;

	system("pause");
}

bool checkIfConflict(int boardSize, stack<BoardSpaces> filledSpaces, BoardSpaces currentSpace)
{
	if (filledSpaces.size() > 0)
	{
		if (abs(filledSpaces.top().getColumn() - currentSpace.getColumn()) <= 1)
		{
			return true;
		}
		else
		{
			filledSpaces.pop();
			while (!filledSpaces.empty())
			{
				if (filledSpaces.top().getRow() == currentSpace.getRow())
				{
					return true;
				}
				if (filledSpaces.top().getColumn() == currentSpace.getColumn())
				{
					return true;
				}
				else if ((abs(filledSpaces.top().getRow() - currentSpace.getRow())) == (abs(currentSpace.getColumn() - filledSpaces.top().getColumn())))
				{
					return true;
				}
				filledSpaces.pop();
			}
		}
	}
	return false;
}

void n_QueensMenu()
{
	n_Queens game;
	game.placeFirstQueen();
	do
	{
		break;

	} while (true);

}