#include "Anzeige.h"
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

/* Output via Operator Overload
//template
ostream& operator << (ostream& lhs, map<string, Feld> spielstand) {

	// Input of lhs
	lhs << endl << endl;
	for (char c = '8'; c >= '1'; c--) {
		lhs << string(10, ' ') << c << " ";
		for (char d = 'A'; d <= 'H'; d++) {
			lhs << spielstand[string(1, d) + c].get_Figur()->get_Bezeichnung();
		}
		lhs << endl;
	}
	lhs << string(10, ' ') << "  ABCDEFGH";
	lhs << endl;

	return lhs;
}
*/