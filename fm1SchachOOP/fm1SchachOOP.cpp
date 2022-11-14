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
		Anzeige::anzeigeSpielstand(s.get_Spielstand());
		cout << endl;
		// Operator overload
		cout << s.get_Spieler();


		s.ziehen();

		// Pausieren der Ausgabe
		cout << endl << endl;
		system("Pause");
	} while (true);
}