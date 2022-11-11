#include "Laeufer.h"

Laeufer::Laeufer()
{
	std::cout << "Laeufer erstellt";
}

Laeufer::Laeufer(bool symbol) {
	farbe = symbol;
	bezeichnung = (symbol) ? 'L' : 'l';
}

std::vector<std::string> Laeufer::erlaubteFelderBerechnen(std::string)
{
	return {};
}
