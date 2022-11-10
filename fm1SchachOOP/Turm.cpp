#include "Turm.h"

Turm::Turm(bool symbol) {
	farbe = symbol;
	bezeichnung = (symbol) ? 'T' : 't';
}

std::vector<std::string> Turm::erlaubteFelderBerechnen()
{
	return {};
}
