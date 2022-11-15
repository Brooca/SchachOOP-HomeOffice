#include "Dame.h"

Dame::Dame(bool symbol)								
{
	 Figur::farbe = symbol;
	 Figur::bezeichnung = (symbol) ? 'D' : 'd';
}

std::vector<std::string> Dame::erlaubteFelderBerechnen(std::string bezeichnung)
{
	// Calculation
	vector<string> dameV;

		// Tower
		for (auto &value : Turm::erlaubteFelderBerechnen(bezeichnung)) {
			dameV.push_back(value);
		}
		
		// Bishop
		for (auto &value : Laeufer::erlaubteFelderBerechnen(bezeichnung)) {
			dameV.push_back(value);
		}

	return dameV;
}
