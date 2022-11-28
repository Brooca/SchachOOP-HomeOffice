#include "Bauer.h"

Bauer::Bauer(bool symbol)
{
	farbe = symbol;
	bezeichnung = (symbol) ? 'B' : 'b';
}

vector<Feld> Bauer::erlaubteFelderBerechnen(string bezeichnung)
{
	vector<string> BauerV;

	switch (this->farbe) {
	case 0: // b läuft runter
		string x	= "  ";
		x.at(0)		= bezeichnung.at(0);
		x.at(1)		 = bezeichnung.at(1) + 1;
		break;

	case 1: // B läuft hoch

		break;
		}
	return {};
}

