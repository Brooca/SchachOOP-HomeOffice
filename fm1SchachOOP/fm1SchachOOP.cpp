#include <iostream>
#include "Spiel.h"
#include "Anzeige.h"
using namespace std;



int main()
{
	// Initialisierung des Spiels
	Spiel s;

	// Ablauf des Spiels
	do {
		// Anzeige::anzeigeSpielstand(s.get_Spielstand());
		s.ziehen();

		// Operator overload
		// cout << s.get_Spieler().at(0);
		cout << s;

		// Pausieren der Ausgabe
		cout << endl << endl;
		system("Pause");
	} while (true);
}