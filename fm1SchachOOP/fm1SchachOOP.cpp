#pragma once
using namespace std;
#include <iostream>

#include "Spiel.h"

int main()
{
	// Initialisierung des Spiels
	Spiel s;

	// Ablauf des Spiels
	do {
		cout << s;
		s.ziehen();
	} while (true);
}