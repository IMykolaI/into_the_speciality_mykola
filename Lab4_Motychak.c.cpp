// Lab4_Motychak.c.cpp : This file contains the 'main' function. Program execution begins and ends there.
// kulian
#include "pch.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
#define n 5

//prototype
int printArray(int arr[n][n]);
void sortArray(int arr[n][n]);
void mdiagonalArray(int arr[n][n]);
int sumArray(int arr[n][n]);


int main()
{
	int a, b;
	static int arr[n][n];
	a = n;
	b = n;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			printf("Enter the element A[%d][%d]:\t", i + 1, j + 1);
			scanf_s("%d", &arr[i][j]);
		}
	}
	printf("\nYour array:\n\n");
	printArray(arr);
	printf("\n\n");
	sortArray(arr);
	printf("\nYour new array:\n\n");
	printArray(arr);
	mdiagonalArray(arr);
	printf("\n\n");
	sumArray(arr);
	printf("\n\n");
	
}

int printArray(int arr[][n])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", arr[i][j]);
		}
		printf("\n\n");
	}
	return 0;
}

void mdiagonalArray(int arr[][n])
{
	int i = 0, j;
	j = i;
	printf("Main diagonal elements:\n\n");
	for (i; i < n; i++, j++)
	{
		printf("%d\t", arr[i][j]);
	}
}

int sumArray(int arr[][n])
{
	int i, j, sum,  k = 0;
	double qqrt, ser = 1;
	for (j = 0; j < n; j++)
	{
		sum = 0;
		for (i = j + 1; i < n; i++)
		{
			sum += arr[i][j];
		}
		printf("Sum of the elements of the %d column is %d\n", j + 1, sum);
		if (j != n - 1)
		{
			ser *= sum;
			k += 1;
		}
		else
		{
			qqrt = pow(fabs(ser), pow(k, -1));
			printf("\n\nMiddle geometric meaning is %lf", qqrt);
		}
	}
	return 0;
}

void sortArray(int arr[][n])
{
	int i, k, j, x;
	for (i = 0; i <= n - 1; i++)
	{
		for (k = 1; k <= n - 1; k++)
		{
			x = arr[i][k];
			for (j = k - 1; j >= 0 && arr[i][j] < x; j--)
			{
				arr[i][j + 1] = arr[i][j];
				arr[i][j] = x;
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
