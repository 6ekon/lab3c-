#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctime>
#include <ctype.h>
#include <cstring>
#include <sstream>
using namespace std;

void task1()
{
	const int N = 5, M = 4;
	int count = 0, count2 = 0;
	char matrix[N][M];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			matrix[i][j] = rand() % 255;
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (matrix[i][j] == '+')
				count++;
			else if (matrix[i][j] == '*')
				count2++;
		}
	}
	cout << "\nAmount of + : " << count;
	cout << "\nAmount of * : " << count2;
}

void task2()
{
	const int N = 14;
	char matrix[N], matrix2[N];
	char* lex;
	int i = 0, mSize = 0, am = 0;
	string words[100];
	cout << "Please enter 14 characters containing a space: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(matrix, sizeof(matrix), '.');
	strcpy_s(matrix2, matrix);
	cout << "Your array: ";
	cout << matrix << endl;
	lex = strtok(matrix, " ,.!?");
	while (lex)
	{
		words[i] = lex;
		if (mSize < words[i].size())
		{
			mSize = words[i].size();
			am = i;
		}
		lex = strtok(NULL, " ,.!?");
		i++;
	}
	cout << "The longest word is: " << words[am];
}

void task3()
{
	const int N = 20;
	char A[N], B[N];
	cout << "A = ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(A, sizeof(A), '.');
	cout << "B = ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(B, sizeof(B), '.');
	int lengthB = strlen(B), k;
	bool flag = true;
	char* c;
	for (int i = 0; i < lengthB; i++)
	{
		if (!strchr(A, B[i]))
		{
			flag = false;
			break;
		}
		else
		{
			c = A;
			k = 0;
			for (char* p = A; *p; p++)
			{
				if (*p != B[i] || k)
				{
					*c = *p;
					c++;
				}
				else k = 1;
			}
			*c = '\0';
		}
	}
	if (flag)
	{
		cout << "Yes!\n";
	}
	else
	{
		cout << "No!\n";
	}
}

int main()
{
	srand(time(NULL));
	int task;
	cout << "Choose your task (available 1, 2, 3): ";
	cin >> task;
	switch (task)
	{
	case 1:
		task1();
		break;
	case 2:
		task2();
		break;
	case 3:
		task3();
		break;
	}
	return 0;
}