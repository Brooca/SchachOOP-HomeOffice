#include "Laeufer.h"

extern Spiel s;

Laeufer::Laeufer(bool symbol) {
	farbe = symbol;
	bezeichnung = (symbol) ? 'l' : 'L';
}

vector<Feld> Laeufer::erlaubteFelderBerechnen(string bezeichnung)
{
	//! Documentation:
	/*	- ein Dummy - String "destination" dient als Zwischenkopie der Startkoordinate und wird iteriert je nach Richtung
	*	- hierzu erhoehen die werte aus der pair-Direction die Koordinate um ihren Wert in jedem durchlauf
	*	- solange onboard die resultierende koordinate noch als auf dem Brett identifiziert
	*	- auch nur dann wird diese Koordinate als erlaubtesFeld aufgenommen
	*/

	//! Variablen
	vector<Feld> felder;
	vector<string> LaeuferV;
	vector<pair<int,int>> direction;
	bool onboard;
	string destination = bezeichnung;

	//! Diagonal								  A+   1+
	pair<int, int> rechtsHoch	= make_pair(  1	,  1 );	// B2, C3 ...
	pair<int, int> rechtsRunter	= make_pair(  1	, -1 );	// B0 ...
	pair<int, int> linksHoch	= make_pair( -1	,  1 );
	pair<int, int> linksRunter	= make_pair( -1	, -1 );

	//! Vector mit Koordinaten fuer die Zielfeld-Pruefung wird iteriert
	direction = { rechtsHoch, rechtsRunter, linksHoch, linksRunter };

	for(unsigned int i = 0 ; i < direction.size(); i++){
		destination = bezeichnung;
		do {
			// Ziel Koordinaten werden ermittelt
			destination.at(0) += direction.at(i).first;
			destination.at(1) += direction.at(i).second;

			// Pruefung ob diese Koordinate noch auf dem Feld ist
			onboard = ((destination.at(0) >= 'A' && destination.at(0) <= 'H' && destination.at(1) >= '1' && destination.at(1) <= '8')) ? 1 : 0;

			// Hinzufuegen des String-Feldes
			if (onboard)
			{
				if (s.get_Spielstand()[destination].get_Figur()->get_Bezeichnung() == ' ')			{ LaeuferV.push_back(destination); }
				else if (this->farbe == s.get_Spielstand()[destination].get_Figur()->get_Farbe())	{ break; }
				else if (this->farbe != s.get_Spielstand()[destination].get_Figur()->get_Farbe())	{ LaeuferV.push_back(destination); break; }
			}
		} while (onboard);
	}

	//! Sort vector ascending
	sort(LaeuferV.begin(), LaeuferV.end());

	//! Convert vector<string> into vector<Feld>
	for (string& str : LaeuferV) { felder.push_back(s.get_Spielstand()[str]); }

	//! Return
	return felder;
}