#include "Anzeige.h"

void Anzeige::anzeigeSpielstand(map<string, Feld> spielstand)
{
	unsigned int counter = 0;
	map<string, Feld>::iterator pos;


	// Feld Bezeichnungen
	// Version 1
	cout << "Version 1:\n";
	for (pos = --spielstand.end(); pos != spielstand.begin(); pos--) {
		cout << (*pos).second.get_Bezeichnung();
		counter++;
		if (counter % 8 == 0)
			cout << "\n";
	}

	// Version 2 
	/**
	for (pos = spielstand.end(); pos != spielstand.begin(); pos--) {



		counter++;
		if (counter % 8 == 0)
			cout << "\n";
	}
	/**/
	

	// Figuren - Bezeichnungen
	// Version 1
	cout << "Version 1 _ Bezeichnung:\n";
	cout << endl;
	for (pos = spielstand.begin(); pos != spielstand.end(); pos++) {
		cout << (*pos).second.get_Figur()->get_bezeichnung();
		counter++;
		if (counter % 8 == 0)
			cout << "\n";
	}
	
}
