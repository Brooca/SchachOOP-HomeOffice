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
		s.ziehen();
		cout << s;

		// Pausieren der Ausgabe
		cout << endl << endl;
		system("Pause");
	} while (true);
}