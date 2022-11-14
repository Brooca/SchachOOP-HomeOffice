#include "Dame.h"
#include <iostream>
using namespace std;

Dame::Dame(bool symbol)								
{
	// Output
	std::cout << "Dame::Dame(bool symbol)" << std::endl;

	// Figur:: in cause of anzeige.cpp asks for ...get_figur().get_Bezeichnung()
	 Figur::farbe = symbol;
	 Figur::bezeichnung = (symbol) ? 'D' : 'd';
}

std::vector<std::string> Dame::erlaubteFelderBerechnen(std::string bezeichnung)
{
	// Output
	cout << "std::vector<std::string> Dame::erlaubteFelderBerechnen(std::string bezeichnung)\n";

	// Calculation
	vector<string> dameV;

		// Tower
		for (auto &value : Turm::erlaubteFelderBerechnen(bezeichnung)) {
			dameV.push_back(value);
		}
		cout << endl;
		// Bishop
		for (auto &value : Laeufer::erlaubteFelderBerechnen(bezeichnung)) {
			dameV.push_back(value);
		}

		// Output
		std::cout << "Erlaubte Felder von Dame auf " << bezeichnung << " : ";
		for (auto &value : dameV) {
			cout << value << " ";
		}

	return dameV;
}
