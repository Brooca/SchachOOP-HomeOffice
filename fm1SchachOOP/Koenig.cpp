#include "Koenig.h"

extern Spiel s;
Koenig::Koenig(bool symbol)
{
	farbe = symbol;
	bezeichnung = (symbol) ? 'K' : 'k';
}

vector<Feld> Koenig::erlaubteFelderBerechnen(string bezeichnung)
{
	// Documentation :
	/*	- anhand der Ausgangsposition werden alle potentiellen Zielfelder formuliert und in einem Vector gesammelt
	*	- beim iterieren wird geprueft ob die Felder onboard sind
	*	- je nach Inhalt des Feldes kann es hinzugefuegt werden
	*	- die Convertierung in einen vector<Feld> erfolgt zum Ende
	*/

	// Variablen
	vector<Feld> felder;
	vector<string> KoenigV;
	vector<pair<char, char>> direction;
	bool onboard;
	string destination = bezeichnung;
	
	// Diagonal
	pair<char, char> rechtsHoch		= make_pair(destination.at(0) + 1, destination.at(1) + 1);
	pair<char, char> rechtsRunter	= make_pair(destination.at(0) + 1, destination.at(1) - 1);
	pair<char, char> linksHoch		= make_pair(destination.at(0) - 1, destination.at(1) + 1);
	pair<char, char> linksRunter	= make_pair(destination.at(0) - 1, destination.at(1) - 1);

	// Vertical & Horizontal
	pair<char, char> Hoch			= make_pair(destination.at(0)	 , destination.at(1) + 1);
	pair<char, char> Runter			= make_pair(destination.at(0)	 , destination.at(1) - 1);
	pair<char, char> Links			= make_pair(destination.at(0) - 1, destination.at(1)	);
	pair<char, char> Rechts			= make_pair(destination.at(0) + 1, destination.at(1)	);

	// Vector mit Koordinaten fuer die Zielfeld-Pruefung wird iteriert
	direction = { rechtsHoch, rechtsRunter, linksHoch, linksRunter, Hoch, Runter, Links, Rechts };

	for(unsigned int i = 0; i < direction.size(); i++) {

		// Ziel Koordinaten werden ermittelt
		destination.at(0) = direction.at(i).first;
		destination.at(1) = direction.at(i).second;

		// Pruefung ob diese Koordinate noch auf dem Feld ist
		onboard = ((destination.at(0) >= 'A' && destination.at(0) <= 'H' && destination.at(1) >= '1' && destination.at(1) <= '8')) ? 1 : 0;

		// Hinzufuegen des String-Feldes
		if (onboard)
		{
			if (s.get_Spielstand()[destination].get_Figur()->get_Bezeichnung() == ' ')
			{
				KoenigV.push_back(destination);
			}
			else if (this->farbe == s.get_Spielstand()[destination].get_Figur()->get_Farbe())
			{
			}
			else if (this->farbe != s.get_Spielstand()[destination].get_Figur()->get_Farbe())
			{
				KoenigV.push_back(destination);
			}
		}
	}

	// Convert vector<string> into vector<Feld>
	for (string& str : KoenigV) { felder.push_back(s.get_Spielstand()[str]); }

	// Return
	return felder;
}
