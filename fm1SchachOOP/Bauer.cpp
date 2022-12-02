#include "Bauer.h"

extern Spiel s;

Bauer::Bauer(bool symbol)
{
	farbe = symbol;
	bezeichnung = (symbol) ? 'b' : 'B';
}

vector<Feld> Bauer::erlaubteFelderBerechnen(string bezeichnung)
{
	// Documentation:
	/*	- mittels eines Switches wird fuer die schwarzen (0) und weissen (1) Bauern unterschieden, Steuer-Variable ist die Farbe der Figur 
		- der Bauer kann am anfang zwei sonst ein Feld weiter laufen
		- diagonal schlagen
		-> TODO : eine Umwandlung der Figur auf Linie 8 und 1 ist noch zu implementieren
	*/

	// Variables
	vector<Feld> felder;
	vector<string> BauerV;
	string x = "  ";

	// Calculation
	switch (this->farbe) {

	// b laeuft runter-------------------------------------------------------------------------------------------------------------------
	case 1:

		// einfacher Schritt
		if (bezeichnung.at(1) != '1' && bezeichnung.at(1) != '7')
		{
			// Destination field
			x.at(0) = bezeichnung.at(0);
			x.at(1) = bezeichnung.at(1) - 1;

			// Add Field
			if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ') { BauerV.push_back(x); }
		}

		// doppelter Schritt zum Anfang
		if (bezeichnung.at(1) == '7') {

			// Destination field
			x.at(0) = bezeichnung.at(0);
			x.at(1) = bezeichnung.at(1) - 1;

			// Freeway
				// Add Field
				if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ') { BauerV.push_back(x);

				// Zweiter Schritt
				x.at(1) = bezeichnung.at(1) - 2;

				// Add Field
				if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ') { BauerV.push_back(x); }
			}
		}

		// b schlaegt rechts runter
		if ( bezeichnung.at(0) < 'H' && bezeichnung.at(1) != '1')
		{
			x.at(0) = bezeichnung.at(0) + 1;
			x.at(1) = bezeichnung.at(1) - 1;

			if (this->farbe != s.get_Spielstand()[x].get_Figur()->get_Farbe() && s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() != ' ')
			{ BauerV.push_back(x); }
		}

		// b schlaegt links runter
		if (bezeichnung.at(0) > 'A' && bezeichnung.at(1) != '1')
		{
			x.at(0) = bezeichnung.at(0) - 1;
			x.at(1) = bezeichnung.at(1) - 1;

			if (this->farbe != s.get_Spielstand()[x].get_Figur()->get_Farbe() && s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() != ' ')
			{ BauerV.push_back(x); }
		}
		break;

	// B laeuft hoch -----------------------------------------------------------------------------------------------------------------------------
	case 0:

	/*Geradeaus*/
		// einfacher Schritt
		if (bezeichnung.at(1) != '2' && bezeichnung.at(1) != '8')
		{
			x.at(0) = bezeichnung.at(0);
			x.at(1) = bezeichnung.at(1) + 1;

			if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ') { BauerV.push_back(x); }
		}

		// doppelter Schritt zum Anfang
		if (bezeichnung.at(1) == '2') {

			x.at(0) = bezeichnung.at(0);
			x.at(1) = bezeichnung.at(1) + 1;

			// Freeway
				if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ') { BauerV.push_back(x);
				x.at(1) = bezeichnung.at(1) + 2;

				if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ') { BauerV.push_back(x); }
			}
		}

	/*Diagonal Schlagen*/
		// B schlaegt rechts hoch
		if (bezeichnung.at(0) < 'H' && bezeichnung.at(1) < '8')
		{ 
			x.at(0) = bezeichnung.at(0) + 1;
			x.at(1) = bezeichnung.at(1) + 1;

			if (this->farbe != s.get_Spielstand()[x].get_Figur()->get_Farbe() && s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() != ' ')
			{ BauerV.push_back(x); }
		}

			
		// B schlägt links hoch
		if (bezeichnung.at(0) > 'A' && bezeichnung.at(1) < '8')
		{
			x.at(0) = bezeichnung.at(0) - 1;
			x.at(1) = bezeichnung.at(1) + 1;

			if (this->farbe != s.get_Spielstand()[x].get_Figur()->get_Farbe() && s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() != ' ')
			{ BauerV.push_back(x); }
		}
	}

	//! Result -------------------------------------------------------------------------------------------------------------------------------
	// Sort vector ascending
	sort(BauerV.begin(), BauerV.end());

	// Convert vector<string> into vector<Feld>
	for (string& str : BauerV) { felder.push_back(s.get_Spielstand()[str]); }

	// Return
	return felder;
}

