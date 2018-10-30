// Lab3_Motychak.c.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
	double x, z = 0, k, upper, lower, step, limit;
	int n = 1;
	printf("Enter the least and the biggest values of x\n");
	scanf_s("%lf%lf", &lower, &upper);
	printf("Enter the step\n");
	scanf_s("%lf", &step);
	printf("Enter limit value\n");
	scanf_s("%lf", &limit);
	for (x = lower; x <= upper + (step / 2); x += step)
	{
		for (n = 1;; n++)
		{
			k = pow(x - 1, 2 * n + 1) / ((2 * n + 1)*pow(x + 1, 2 * n + 1));
			if (fabs(k) >= limit)
			{
				z += k;
			}
			else
			{
				printf("x=%lf\tz=%.9f\n", x, 2 * z);
				break;
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
