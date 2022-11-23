#include "Laeufer.h"

Laeufer::Laeufer(bool symbol) {
	farbe = symbol;
	bezeichnung = (symbol) ? 'L' : 'l';
}

vector<Feld> Laeufer::erlaubteFelderBerechnen(string bezeichnung)
{
		// Calculation
		vector<string> LaeuferV;
		for (int i = 0; i < 8; i++)
		{
			for (int k = 7; k >= 0; k--)
			{
				if (bezeichnung.at(0) == (65 + i))
				{
					string x = "  ";
					x.at(0) = bezeichnung.at(0) + k - i;
					x.at(1) = bezeichnung.at(1);
					if (x.at(0) != (65 + i))
					{
						LaeuferV.push_back(x);
					}
				}
				if (bezeichnung.at(1) == (49 + i))
				{
					string x = "  ";
					x.at(0) = bezeichnung.at(0);
					x.at(1) = bezeichnung.at(1) + k - i;
					if (x.at(1) != (49 + i))
					{
						LaeuferV.push_back(x);
					}
				}
			}
		}
		vector<Feld> felder;
		for (string& str : LaeuferV) {
			felder.push_back(s.get_Spielstand()[str]);
		}
	return {};
}
