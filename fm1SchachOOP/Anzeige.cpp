#include "Anzeige.h"
#include "Spiel.h"
#include <string>

// Output via function
void Anzeige::anzeigeSpielstand(map<string, Feld> spielstand)
{ cout << endl << endl;
	
	// Output : Figur auf Feld passend zur Bezeichnung
	for (char c = '8'; c >= '1'; c--) {

		// Distance to terminal edge
		cout << string(10, ' ') << c << " ";

		// Field
		for (char d = 'A'; d <= 'H'; d++) {
			cout << spielstand[string(1, d) + c].get_Figur()->get_Bezeichnung();
		}
		cout << endl;
	}
	// Underline with characters
	cout << string(10, ' ') << "  ABCDEFGH";

cout << endl;
}

// Output via operator overload - Spieler*in
ostream& operator << (ostream& lhs, array<Spieler, 2> rhs) {
	lhs << "Spieler*in White: " << rhs.at(0).name << "\n" << "Spieler*in Black: " << rhs.at(1).name;
	return lhs;
}