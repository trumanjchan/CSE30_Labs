// IntRepresentation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
//#include <iomanip>

using namespace std;
int main()
{
	int answer;
	cout << "Enter an int value: ";
	cin >> answer;

	int* p = &answer;       // Int Pointer p points to the address of 'answer'
	char* c = (char*)p;     // Char Pointer c points to the string location of 'answer'

	//cout << hex << (int)(*c++) << endl;

	for (int i = 0; i < 4; i++) {
		cout << hex << (int)*(c++) << " ";
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
