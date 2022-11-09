#include "Anzeige.h"

void Anzeige::anzeigeSpielstand(map<string, Feld> spielstand)
{
	unsigned int counter = 0;
	map<string, Feld>::iterator pos;

	for (pos = spielstand.begin(); pos != spielstand.end(); pos++) {
		cout << (*pos).second.get_Bezeichnung();
		counter++;
		if (counter % 8 == 0)
			cout << "\n";
	}
}
