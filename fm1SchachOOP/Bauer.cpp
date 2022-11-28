#include "Bauer.h"

extern Spiel s;

Bauer::Bauer(bool symbol)
{
	farbe = symbol;
	bezeichnung = (symbol) ? 'B' : 'b';
}

vector<Feld> Bauer::erlaubteFelderBerechnen(string bezeichnung)
{
	vector<string> BauerV;
	string x	= "  ";
	switch (this->farbe) {
	case 0:
		
			// b l�uft runter
		if (bezeichnung.at(1) != 49)
		{
			
			x.at(0) = bezeichnung.at(0);
			x.at(1) = bezeichnung.at(1) - 1;
			if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ')
			{
				BauerV.push_back(x);
				break;
			}
			else
			{
				break;
			}
		}

			// b l�uft von startposition 2 runter
		if (bezeichnung.at(1) == 55 && s.get_Spielstand()[bezeichnung.at(0),(bezeichnung.at(1))+1].get_Figur()->get_Bezeichnung() == '  ')
		{
			string x = "  ";
			x.at(0) = bezeichnung.at(0);
			x.at(1) = bezeichnung.at(1) - 2;
				if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ')
				{
					BauerV.push_back(x);
					break;
				}
			
				else
				{
					break;
				}
		}
			// b schl�gt rechts runter
		if(bezeichnung.at(1) != 49 && bezeichnung.at(0) <72 )
		string x	= "  ";
		x.at(0)		= bezeichnung.at(0) + 1;
		x.at(1)		= bezeichnung.at(1) - 1;
		if (this->farbe != s.get_Spielstand()[x].get_Figur()->get_Farbe())
		{
			BauerV.push_back(x);
			break;
		}	
		else
		{
			break;
		}
		
		// b schl�gt links runter
		if (bezeichnung.at(1) != 49 && bezeichnung.at(0) > 65 )
		x.at(0) = bezeichnung.at(0) - 1;
		x.at(1) = bezeichnung.at(1) - 1;
		if (this->farbe != s.get_Spielstand()[x].get_Figur()->get_Farbe())
		{
			BauerV.push_back(x);
			break;
		}
		else
		{
			break;
		}

	case 1: // B l�uft hoch
		/*Geradeaus*/
		// einfacher Schritt ab linie 3
		if (bezeichnung.at(0) >= 'A' && bezeichnung.at(0) <= 'H' && bezeichnung.at(1) >= '3' && bezeichnung.at(1) <= '8')
		{
		x.at(0) = bezeichnung.at(0);
		x.at(1) = bezeichnung.at(1) + 1;
			if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ')
			{
				BauerV.push_back(x);
			}
		}

		// doppelter Schritt zum Anfang
		if (bezeichnung.at(0) >= 'A' && bezeichnung.at(0) <= 'H' && bezeichnung.at(1) == '2') {
			x.at(0) = bezeichnung.at(0);
			x.at(1) = bezeichnung.at(1) + 1;
			// Freeway : wenn ja : Feld hinzufuegen
			if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ')
			{
				BauerV.push_back(x);

				// Zweiter Schritt
				x.at(1) = bezeichnung.at(1) + 2;
				if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ')
				{
					BauerV.push_back(x);
				}
			}
		}
		/*Diagonal Schlagen*/

		break;
	}	
	// Convert vector<string> into vector<Feld>
	vector<Feld> felder;
	for (string& str : BauerV)
	{
		felder.push_back(s.get_Spielstand()[str]);
	}
	// Return
	return felder;
}

