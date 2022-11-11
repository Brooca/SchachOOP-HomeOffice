#include "Leer.h"

Leer::Leer(std::string s)
{
	bezeichnung = (s.at(0) + s.at(1)) % 2 ? 176 : 32;
}

std::vector<std::string> Leer::erlaubteFelderBerechnen(std::string)
{
	return {};
}
