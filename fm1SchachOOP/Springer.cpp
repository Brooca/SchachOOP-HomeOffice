#include "Springer.h"

Springer::Springer(bool symbol)
{
	farbe = symbol;
	bezeichnung = (symbol) ? 'S' : 's';
}

std::vector<std::string> Springer::erlaubteFelderBerechnen()
{
	std::cout << "Springer::erlaubteFelderBerechnen()";
		return {
		"B7"
		};
}
