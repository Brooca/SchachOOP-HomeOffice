#pragma once
using namespace std;

#include <iostream>

#include "Spiel.h"
	// Initialisierung des Spiels
	Spiel s;
int main()
{


	// Ablauf des Spiels
	do {
		s.ziehen();
		cout << s;

		// Pausieren der Ausgabe
		cout << endl << endl;
		system("Pause");
	} while (true);
}