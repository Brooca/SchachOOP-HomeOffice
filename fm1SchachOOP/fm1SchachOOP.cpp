#pragma once
using namespace std;
#include <iostream>

#include "Spiel.h"	

//! Initialisierung des Spiels als globale Variable
Spiel s; 

int main()
{
	//! Ablauf des Spiels
	do {
		cout << s;
		s.ziehen();
		s.set_Zugnummer();
	} while (true);
}