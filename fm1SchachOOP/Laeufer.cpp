#include "Laeufer.h"

extern Spiel s;

Laeufer::Laeufer(bool symbol) {
	farbe = symbol;
	bezeichnung = (symbol) ? 'L' : 'l';
}

vector<Feld> Laeufer::erlaubteFelderBerechnen(string bezeichnung)
{
		// Calculation
		vector<string> LaeuferV;

		for (int j = 0; j < 8; j++)
		{
			for (int n = 7; n >= 0; n--)
			{
				for (int i = 0; i < 8; i++)
				{
					for (int k = 7; k >= 0; k--)
					{
						if (abs(bezeichnung.at(0) - bezeichnung.at(1)) == abs(bezeichnung.at(0 + k - i) - bezeichnung.at(1 + n - j)))
						{
							string x = "  ";
							x.at(0) = bezeichnung.at(0) + k - i;
							x.at(1) = bezeichnung.at(1) + n - j;
								if (x.at(0) != (65 + i))
								{
									LaeuferV.push_back(x);
								}
						}
						
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
