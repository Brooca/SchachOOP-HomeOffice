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
	vector<Feld> zwischenschritt;
	// Datentyp Name (parameter)
	Turm DameTurm(this->farbe)  ;

	// Objekt -> Methode aufrufen
	// Bsp.: spielstand...???..at()

	DameV = DameTurm.erlaubteFelderBerechnen(bezeichnung);
	
	Laeufer DameLaeufer(this->farbe);

	zwischenschritt = DameLaeufer.erlaubteFelderBerechnen(bezeichnung);
	for (auto& bezeichnung : zwischenschritt ) {
		DameV.push_back(bezeichnung);
	}
	


	return DameV;

}
	// DameV <- Turm erlaubte Felder
	// Laeufer erstellen
	// DameV <- Laeufer
	// return dameV


