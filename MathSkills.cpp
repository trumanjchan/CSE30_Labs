// MathSkills.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "TimeSupport.h"

using namespace std;
int main()
{
	int x = 0;
    cout << "Welcome to MathSkills!"; 

	for (int i = 0; i < 10; i++)
		int a = rand() % 10;
	    int b = rand() % 10;
		cout << a << " + " << b << " = " << endl;
		timestamp insertStart = current_time();
	cin >> x;
	timestamp insertEnd = current_time();
	long insertDuration = time_diff(insertStart, insertEnd);

	if (a + b == c)
		cout << "Correct! " << insertDuration << "ms" << endl;
	else
		cout << "Wrong! " << insertDuration << "ms" << endl;
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
