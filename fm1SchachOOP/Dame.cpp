#include "Dame.h"

Dame::Dame(bool symbol)								
{
	 Figur::farbe = symbol;
	 Figur::bezeichnung = (symbol) ? 'D' : 'd';
}

vector<Feld> Dame::erlaubteFelderBerechnen(std::string bezeichnung)
{
	//! Documentation
	/* Es werden jeweils die Felder berechnet als wuerden an der Stelle ein Turm beziehungsweise ein Laeufer stehen.
		- hierzu werden diese Figuren konstruiert und deren Berechnung durchgefuehrt
		- die ergebnisse werden dem vector<Feld> DameV hinzugefuegt

		- Sortieren des Vectors mittels einer Lambda Funktion als dritten Parameter zur eigenen Definition des Vergleichwertes
			- sort vergleicht den einen Wert mit dem naechsten wert
			- die Lamda function gibt true oder false, je nach dem ob die in der Funktion definierte Bedingung zutrifft
			- bei true tauscht sort die Werte, bei false nicht
			-> https://www.geeksforgeeks.org/sorting-a-vector-in-c/
			-> https://www.delftstack.com/de/howto/cpp/sort-vector-in-cpp/	*/

	//! Variables
	vector<Feld> DameV, TurmV, LaeuferV;
	
	//! Dummy Figuren
	Turm Turm(this->farbe);
	Laeufer Laeufer(this->farbe);

	//! Calculation
	TurmV = Turm.erlaubteFelderBerechnen(bezeichnung);
	LaeuferV = Laeufer.erlaubteFelderBerechnen(bezeichnung);

	//! Adding Turm and Laeufer into DameV
	for (auto& feld : TurmV)	{	DameV.push_back(feld);	}
	for (auto& feld : LaeuferV) {	DameV.push_back(feld);	}

	//! sort vector
	sort(DameV.begin(), DameV.end(), []	(Feld& f1, Feld& f2) {	return f1.get_Bezeichnung() < f2.get_Bezeichnung();	}	);

	//! Return
	return DameV;
}


