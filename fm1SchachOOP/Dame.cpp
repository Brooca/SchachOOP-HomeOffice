#include "Dame.h"

Dame::Dame(bool symbol)								
{
	 Figur::farbe = symbol;
	 Figur::bezeichnung = (symbol) ? 'D' : 'd';
}

vector<Feld> Dame::erlaubteFelderBerechnen(std::string bezeichnung)
{
	// Calculation
	vector<Feld> DameV;
	// Datentyp Name (parameter)
	Turm DameTurm(this->farbe)  ;

	// Objekt -> Methode aufrufen
	// Bsp.: spielstand...???..at()
	erlaubteFelderBerechnen().at;
}
	// DameV <- Turm erlaubte Felder
	// Laeufer erstellen
	// DameV <- Laeufer
	// return dameV


