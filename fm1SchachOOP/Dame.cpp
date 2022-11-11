#include "Dame.h"
/*
Dame::Dame() {
	std::cout << "Dame erstellt\n";
}*/

Dame::Dame(bool symbol)
{
	 farbe = symbol;
	 bezeichnung = (symbol) ? 'D' : 'd';
	 std::cout << "Dame::Dame(bool symbol)" << std::endl;
}

std::vector<std::string> Dame::erlaubteFelderBerechnen(std::string)
{
	return {};
}
