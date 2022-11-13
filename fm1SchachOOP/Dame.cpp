#include "Dame.h"

Dame::Dame(bool symbol)								
{
	// Figur:: in cause of anzeige.cpp asks for ...get_figur().get_Bezeichnung()
	 Figur::farbe = symbol;
	 Figur::bezeichnung = (symbol) ? 'D' : 'd';
	 std::cout << "Dame::Dame(bool symbol)" << std::endl;
}

std::vector<std::string> Dame::erlaubteFelderBerechnen(std::string)
{
	return {};
}
