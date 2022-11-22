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
		cout << s;
		s.ziehen();
	} while (true);
}