// Lab4_Motychak.c.cpp : This file contains the 'main' function. Program execution begins and ends there.
// kulian
#include "pch.h"
#include <math.h>
#include <stdio.h>
#define matrixSize 5

static int row, column;

//prototype
int printArrayToConsole(int array[matrixSize][matrixSize]);
void sortElementsOfRowsOfArrayUsingInsertMethodHighToLow(int array[matrixSize][matrixSize]);
void mainDiagonalElementsPrintToConsole(int array[matrixSize][matrixSize]);
double sumOfElementsInEveryColumnUnderMainDiagonalOfMatrix(int array[matrixSize][matrixSize]);
double middleGeometricMeaningOfSumsOfTheElementsUnderMainDiagonal(double temporaryVariableForMiddleGeometricMeaning);


int main()
{
	static int array[matrixSize][matrixSize];
	double temporaryVariable;
	for (row = 0; row < matrixSize; row++)
	{
		for (column = 0; column < matrixSize; column++)
		{
			printf("Enter the element A[%d][%d]:\t", row + 1, column + 1);
			scanf_s("%d", &array[row][column]);
		}
	}

	printf("\nYour array:\n\n");
	printArrayToConsole(array);
	printf("\n\n");
	sortElementsOfRowsOfArrayUsingInsertMethodHighToLow(array);
	printf("\nYour new array:\n\n");
	printArrayToConsole(array);
	mainDiagonalElementsPrintToConsole(array);
	printf("\n\n");
	temporaryVariable = sumOfElementsInEveryColumnUnderMainDiagonalOfMatrix(array);
	middleGeometricMeaningOfSumsOfTheElementsUnderMainDiagonal(temporaryVariable);
	printf("\n\n");

}

int printArrayToConsole(int array[][matrixSize])
{
	for (row = 0; row < matrixSize; row++)
	{
		for (column = 0; column < matrixSize; column++)
		{
			printf("%d\t", array[row][column]);
		}
		printf("\n\n");
	}
	return 0;
}

void mainDiagonalElementsPrintToConsole(int array[][matrixSize])
{
	int row = 0, column;
	column = row;
	printf("Main diagonal elements:\n\n");
	for (row; row < matrixSize; row++, column++)
	{
		printf("%d\t", array[row][column]);
	}
}

double sumOfElementsInEveryColumnUnderMainDiagonalOfMatrix(int array[][matrixSize])
{
	int row, column, sumOfElementsInTheColumn;
	double temporaryVariableForMiddleGeometricMeaning = 1;
	for (column = 0; column < matrixSize; column++)
	{
		sumOfElementsInTheColumn = 0;
		for (row = column + 1; row < matrixSize; row++)
		{
			sumOfElementsInTheColumn += array[row][column];
		}
		printf("Sum of the elements of the %d column is %d\n", column + 1, sumOfElementsInTheColumn);
		if (column != matrixSize - 1)
		{
			temporaryVariableForMiddleGeometricMeaning *= sumOfElementsInTheColumn;
		}
	}
	return temporaryVariableForMiddleGeometricMeaning;
}

double middleGeometricMeaningOfSumsOfTheElementsUnderMainDiagonal(double temporaryVariableForMiddleGeometricMeaning)
{
	double middleGeometricMeaning;
	middleGeometricMeaning = pow(fabs(temporaryVariableForMiddleGeometricMeaning), pow(matrixSize - 1, -1));
	printf("\n\nMiddle geometric meaning is %lf", middleGeometricMeaning);
	return 0;
}

void sortElementsOfRowsOfArrayUsingInsertMethodHighToLow(int array[][matrixSize])
{
	int row, k, column, temporaryVariable;
	for (row = 0; row <= matrixSize - 1; row++)
	{
		for (k = 1; k <= matrixSize - 1; k++)
		{
			temporaryVariable = array[row][k];
			for (column = k - 1; column >= 0 && array[row][column] < temporaryVariable; column--)
			{
				array[row][column + 1] = array[row][column];
				array[row][column] = temporaryVariable;
			}
		}
	}
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
