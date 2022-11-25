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


	DameV = DameTurm.erlaubteFelderBerechnen(bezeichnung);
	
	Laeufer DameLaeufer(this->farbe);

	zwischenschritt = DameLaeufer.erlaubteFelderBerechnen(bezeichnung);

	for (auto& feld : zwischenschritt )
	{
		DameV.push_back(feld);
	}
	


	return DameV;

}


