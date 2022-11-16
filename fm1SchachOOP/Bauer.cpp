#include "Bauer.h"

Bauer::Bauer(bool symbol)
{
	farbe = symbol;
	bezeichnung = (symbol) ? 'B' : 'b';
}

vector<string> Bauer::erlaubteFelderBerechnen(string)
{
	return {};
}

