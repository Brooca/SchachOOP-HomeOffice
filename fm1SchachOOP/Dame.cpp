#include "Dame.h"

Dame::Dame(bool symbol)
{
	farbe = symbol;
	bezeichnung = (symbol) ? 'D' : 'd';
}

std::vector<std::string> Dame::erlaubteFelderBerechnen(std::string)
{
	return {};
}
