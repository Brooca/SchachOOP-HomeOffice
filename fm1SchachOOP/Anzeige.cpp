#include "Anzeige.h"

void Anzeige::anzeigeSpielstand(map<string, Feld> spielstand)
{
	map<string, Feld>::iterator pos;

	for (char c = '8'; c >= '1'; c--) {
		for (char d = 'A'; d <= 'H'; d++) {
			cout << spielstand[string(1, d) + c].get_Figur()->get_bezeichnung();
		}
		cout << endl;
	}
}
