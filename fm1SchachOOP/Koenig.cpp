#include "Koenig.h"

Koenig::Koenig(bool symbol)
{
	farbe = symbol;
	bezeichnung = (symbol) ? 'K' : 'k';
}

std::vector<std::string> Koenig::erlaubteFelderBerechnen(std::string)
{
	return {};
}
