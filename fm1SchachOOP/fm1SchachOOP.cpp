// fm1SchachOOP.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.

#include <iostream>
#include "Spiel.h"
#include "Anzeige.h"

int main()
{
	// Initialisierung des Spiels
	Spiel s;

	// Ablauf des Spiels
	do {
		Anzeige::anzeigeSpielstand(s.get_Spielstand());
		s.ziehen();

		// Pausieren der Ausgabe
		cout << endl << endl;
		system("Pause");
	} while (true);


}