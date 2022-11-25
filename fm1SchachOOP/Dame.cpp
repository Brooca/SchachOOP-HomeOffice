#include "Dame.h"

Dame::Dame(bool symbol)								
{
	 Figur::farbe = symbol;
	 Figur::bezeichnung = (symbol) ? 'D' : 'd';
}

vector<Feld> Dame::erlaubteFelderBerechnen(std::string bezeichnung)
{
	// Calculation
	//vector<Feld> DameV
	// DameV <- Turm erlaubte Felder
	// DameV <- Laeufer
	// return dameV
}
