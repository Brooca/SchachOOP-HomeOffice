#include "Anzeige.h"

void Anzeige::anzeigeSpielstand(map<string, Feld> spielstand)
{ cout << endl << endl;
	
	// Output : Figur auf Feld passend zur Bezeichnung
	for (char c = '8'; c >= '1'; c--) {
		for (char d = 'A'; d <= 'H'; d++) {
			cout << spielstand[string(1, d) + c].get_Figur()->get_Bezeichnung();
		}
		cout << endl;
	}

cout << endl;
}
