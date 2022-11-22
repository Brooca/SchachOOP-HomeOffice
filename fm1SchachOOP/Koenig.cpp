#include "Koenig.h"

Koenig::Koenig(bool symbol)
{
	farbe = symbol;
	bezeichnung = (symbol) ? 'K' : 'k';
}

vector<Feld> Koenig::erlaubteFelderBerechnen(string)
{
	return {};
}
