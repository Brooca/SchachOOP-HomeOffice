#include "Bauer.h"

extern Spiel s;

Bauer::Bauer(bool symbol)
{
	farbe = symbol;
	bezeichnung = (symbol) ? 'B' : 'b';
}

vector<Feld> Bauer::erlaubteFelderBerechnen(string bezeichnung)
{
	vector<string> BauerV;
	string x	= "  ";
	switch (this->farbe) {
	case 0: // b läuft runter

		x.at(0) = bezeichnung.at(0);
		x.at(1) = bezeichnung.at(1) + 1;
		break;

	case 1: // B läuft hoch
		x.at(0) = bezeichnung.at(0);
		x.at(1) = bezeichnung.at(1) + 1;

		if (x.at(0) >= 65 && x.at(0) <= 72 && x.at(1) >= 49 && x.at(1) <= 56)
		{
			if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ')
			{
				BauerV.push_back(x);

			}
		}
		break;
	}	
	// Convert vector<string> into vector<Feld>
	vector<Feld> felder;
	for (string& str : BauerV)
	{
		felder.push_back(s.get_Spielstand()[str]);
	}
	// Return
	return felder;
}

