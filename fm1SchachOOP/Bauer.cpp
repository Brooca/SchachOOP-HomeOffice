#include "Bauer.h"

Bauer::Bauer(bool symbol)
{
	farbe = symbol;
	bezeichnung = (symbol) ? 'B' : 'b';
}

vector<Feld> Bauer::erlaubteFelderBerechnen(string)
{
	return {};
}

