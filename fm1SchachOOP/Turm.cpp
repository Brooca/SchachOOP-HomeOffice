#include "Turm.h"

Turm::Turm()
{
	std::cout << "Turm erstellt\n";
}

Turm::Turm(bool symbol) {
	farbe = symbol;
	bezeichnung = (symbol) ? 'T' : 't';
}

std::vector<std::string> Turm::erlaubteFelderBerechnen(std::string)
{
	return {};
}
