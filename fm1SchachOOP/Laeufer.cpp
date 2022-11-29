#include "Laeufer.h"

extern Spiel s;

Laeufer::Laeufer(bool symbol) {
	farbe = symbol;
	bezeichnung = (symbol) ? 'L' : 'l';
}

vector<Feld> Laeufer::erlaubteFelderBerechnen(string bezeichnung)
{
	// Documentation:
	/*	- ein Dummy - String dient als Zwischenkopie der Startkoordinate und wird iteriert je nach Richtung
	*	- solange onboard die resultierende koordinate noch als auf dem Brett identifiziert
	*	- auch nur dann wird diese Koordinate als erlaubtesFeld aufgenommen
	*/

	// Variablen
	vector<Feld> felder;
	vector<string> LaeuferV;
	string destination;
	bool onboard;

	// Rechts Hoch
	destination = bezeichnung;
	onboard = true;

	while (onboard) {
		
		// Ziel Koordinaten werden ermittelt
		destination.at(0)++;
		destination.at(1)++;

		// Pruefung ob diese Koordinate noch auf dem Feld ist
		onboard = ((destination.at(0) >= 'A' && destination.at(0) <= 'H' && destination.at(1) >= '1' && destination.at(1) <= '8')) ? 1 : 0;

		// Hinzufuegen des String-Feldes
		if (onboard)
		{
			if (s.get_Spielstand()[destination].get_Figur()->get_Bezeichnung() == ' ')
			{
				LaeuferV.push_back(destination);
			}
			else if (this->farbe == s.get_Spielstand()[destination].get_Figur()->get_Farbe())
			{
				break;
			}
			else if (this->farbe != s.get_Spielstand()[destination].get_Figur()->get_Farbe())
			{
				LaeuferV.push_back(destination);
				break;
			}
		}
	}

	// Rechts runter
	destination = bezeichnung;
	onboard = true;

	while (onboard) {
		destination.at(0)++;
		destination.at(1)--;

		onboard = ((destination.at(0) >= 'A' && destination.at(0) <= 'H' && destination.at(1) >= '1' && destination.at(1) <= '8')) ? 1 : 0;

		if (onboard)
		{
			if (s.get_Spielstand()[destination].get_Figur()->get_Bezeichnung() == ' ')
			{
				LaeuferV.push_back(destination);
			}
			else if (this->farbe == s.get_Spielstand()[destination].get_Figur()->get_Farbe())
			{
				break;
			}
			else if (this->farbe != s.get_Spielstand()[destination].get_Figur()->get_Farbe())
			{
				LaeuferV.push_back(destination);
				break;
			}
		}
	}

	// Links Runter
	destination = bezeichnung;
	onboard = true;

	while (onboard) {
		destination.at(0)--;
		destination.at(1)--;

		onboard = ((destination.at(0) >= 'A' && destination.at(0) <= 'H' && destination.at(1) >= '1' && destination.at(1) <= '8')) ? 1 : 0;

		if (onboard)
		{
			if (s.get_Spielstand()[destination].get_Figur()->get_Bezeichnung() == ' ')
			{
				LaeuferV.push_back(destination);
			}
			else if (this->farbe == s.get_Spielstand()[destination].get_Figur()->get_Farbe())
			{
				break;
			}
			else if (this->farbe != s.get_Spielstand()[destination].get_Figur()->get_Farbe())
			{
				LaeuferV.push_back(destination);
				break;
			}
		}
	}

	// Links hoch
	destination = bezeichnung;
	onboard = true;

	while (onboard) {
		destination.at(0)--;
		destination.at(1)++;

		onboard = ((destination.at(0) >= 'A' && destination.at(0) <= 'H' && destination.at(1) >= '1' && destination.at(1) <= '8')) ? 1 : 0;

		if (onboard)
		{
			if (s.get_Spielstand()[destination].get_Figur()->get_Bezeichnung() == ' ')
			{
				LaeuferV.push_back(destination);
			}
			else if (this->farbe == s.get_Spielstand()[destination].get_Figur()->get_Farbe())
			{
				break;
			}
			else if (this->farbe != s.get_Spielstand()[destination].get_Figur()->get_Farbe())
			{
				LaeuferV.push_back(destination);
				break;
			}
		}
	}

	// Convert vector<string> into vector<Feld>
	for (string& str : LaeuferV) { felder.push_back(s.get_Spielstand()[str]); }

	// Return
	return felder;
}