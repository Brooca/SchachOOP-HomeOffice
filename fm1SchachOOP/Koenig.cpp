#include "Koenig.h"

Koenig::Koenig(bool symbol)
{
	farbe = symbol;
	bezeichnung = (symbol) ? 'K' : 'k';
}

vector<string> Koenig::erlaubteFelderBerechnen(string)
{
	return {};
}
