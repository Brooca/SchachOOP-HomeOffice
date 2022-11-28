#include "Dame.h"

Dame::Dame(bool symbol)								
{
	 Figur::farbe = symbol;
	 Figur::bezeichnung = (symbol) ? 'D' : 'd';
}

vector<Feld> Dame::erlaubteFelderBerechnen(std::string bezeichnung)
{
	// Documentation
	/* Es werden jeweils die Felder berechnet als wuerden an der Stelle ein Turm beziehungsweise ein Laeufer stehen.
		- hierzu werden diese Figuren konstruiert und deren Berechnung durchgefuehrt
		- die ergebnisse werden dem vector<Feld> DameV hinzugefuegt */

	// Variables
	vector<Feld> DameV, TurmV, LaeuferV;
	
	// Dummy Figuren
	Turm Turm(this->farbe);
	Laeufer Laeufer(this->farbe);

	TurmV = Turm.erlaubteFelderBerechnen(bezeichnung);
	LaeuferV = Laeufer.erlaubteFelderBerechnen(bezeichnung);

	// Adding Turm and Laeufer into DameV
	for (auto& feld : TurmV) { DameV.push_back(feld); }
	for (auto& feld : LaeuferV) {	DameV.push_back(feld);	}

	// Return
	return DameV;
}


