#include "Turm.h"
// TODO DOKU externes Spiel warum und so
extern Spiel s;

Turm::Turm(bool symbol) {
	farbe = symbol;
	bezeichnung = (symbol) ? 'T' : 't';
}

vector<Feld> Turm::erlaubteFelderBerechnen(string bezeichnung)
{
	// Calculation
	vector<string> TurmV;
	for (int i = 0; i < 8; i++)
	{
		for(int k = 7; k >= 0; k--)
		{
		if (bezeichnung.at(0) == (65 + i))
			{
			string x = "  ";
				x.at(0) = bezeichnung.at(0) + k - i;
				x.at(1) = bezeichnung.at(1);
				if (x.at(0) != (65 + i))
				{
					TurmV.push_back(x);  
				}
			}
			if (bezeichnung.at(1) == (49 + i))
			{
				string x = "  ";
				x.at(0) = bezeichnung.at(0) ;
				x.at(1) = bezeichnung.at(1) + k - i;
				if (x.at(1) != (49 + i))
				{
					TurmV.push_back(x);
				}
			}
		}
	}
	vector<Feld> felder;
	for (string& str : TurmV) {
		felder.push_back(s.get_Spielstand()[str]);
	}
	
	return felder;
}
