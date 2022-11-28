#include "Bauer.h"

Bauer::Bauer(bool symbol)
{
	farbe = symbol;
	bezeichnung = (symbol) ? 'B' : 'b';
}

vector<Feld> Bauer::erlaubteFelderBerechnen(string)
{
	vector<string> BauerV;

	switch (this->farbe) {
	case 0:

		break;

	case 1:

		break;
		}
	return {};
}

