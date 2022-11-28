#include "Koenig.h"

extern Spiel s;
Koenig::Koenig(bool symbol)
{
	farbe = symbol;
	bezeichnung = (symbol) ? 'K' : 'k';
}

vector<Feld> Koenig::erlaubteFelderBerechnen(string bezeichnung)
{

	// Calculation
	vector<string> KoenigV;
	for (int m = 0; m < 2; m++)						// 0 = horizonal; 1 = vertical
	{
		for (int n = 0; n < 3; n += 2)				// 0 = Horizontal Links & vertikal runter; 2 = Horizontal rechts & vertikal hoch
		{
			for (int i = 0; i < 8; i++)				
			{
				for (int k = 0; k < 8; k++)
				{
					// Berechnung der erlaubten Felder 								
					if (bezeichnung.at(m) == (65 + i - (16 * m)))													// Feld auf dem man steht				| 65 + 0 = A 		
					{
						string x = "  ";
						x.at(m) = bezeichnung.at(m) + k - (k * n);												// Feld auf das man sich bewegen kann	| 65 + 0 = A 		
						x.at(1 - m) = bezeichnung.at(1 - m);														// vertikale / horizontale bleibt unverändert		
						if (x.at(m) != (65 + i - (16 * m)) && x.at(m) >= 65 - (16 * m) && x.at(m) <= 72 - (16 * m)) // Felder auf dem man steht excludieren & nur on Board range erlauben		
						{
							if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ')						// Wenn das Feld leer ist, ist es erlaubt -> pushback
							{
								KoenigV.push_back(x);

							}
							else if (this->farbe == s.get_Spielstand()[x].get_Figur()->get_Farbe())					// Wenn die Figur auf dem Feld die selbe Farbe hat als diese Figur kein pushback & break
							{
								break;
							}
							else if (this->farbe != s.get_Spielstand()[x].get_Figur()->get_Farbe())					// Wenn die Figur auf dem Feld eine andere Farbe hat als diese Figur, ist es erlaubt -> pushback & danach break
							{
								KoenigV.push_back(x);
								break;
							}
						}
					}
				}
			}
		}
	}
	vector<Feld> felder;
	for (string& str : KoenigV)
	{
		felder.push_back(s.get_Spielstand()[str]);
	}

	return felder;

}
