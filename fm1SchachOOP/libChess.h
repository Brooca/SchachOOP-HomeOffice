#pragma once
using namespace std;
#include <iostream>
#include <vector>
#include <array>
#include <Windows.h>

// Funktion set Cursor
void setCursorPosition(unsigned int x, unsigned int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}

// Operator Overload Templates
// Vector
template<typename T>
ostream& operator << (ostream& lhs, vector<T>& rhs) {
	for (T arg: rhs) {
		lhs << arg << " ";
	}
	return lhs;
}

// Array
template<typename T, unsigned int U>
ostream& operator << (ostream& lhs, array<T,U>& rhs) {
	for (T arg : rhs) {
		lhs << arg << " ";
	}
	return lhs;
}