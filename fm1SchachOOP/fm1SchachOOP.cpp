#pragma once
using namespace std;
#include <iostream>

#include "Spiel.h"
Spiel s;
int main()
{
	// Initialisierung des Spiels
	

	// Ablauf des Spiels
	do {
		cout << s;
		s.ziehen();
		s.set_zugnummer();
	} while (true);
}