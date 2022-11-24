#include "Springer.h"

extern Spiel s;

Springer::Springer(bool symbol)
{
	farbe = symbol;
	bezeichnung = (symbol) ? 'S' : 's';
}

std::vector<Feld> Springer::erlaubteFelderBerechnen(std::string bezeichnung)
{ 
	// Documentation
	/*	- Abhaengig von dem Bereich des Schachbretts auf dem die Positon des Springers zu verorten ist,
		  werden die zwei moegliche Felder berechnet zu denen eine Bewegung moeglich ist.
		- Wenn diese leer oder mit einer gegnerischen Figur besetzt sind werden sie  den erlaubten Feldern
		  hinzugefuegt.

	Bewegungsmuster : Springer
		c = A d = 1
		c + 2 & d +1 || c + 2 & d - 1
		c - 2 & d + 1 || c - 2 & d - 1
		d + 2 & c + 1 || d + 2 & c - 1
		d + 2 & c + 1 || d + 2 & c - 1
	*/

	// Calculation
	vector<string>springerV;

	for(int i : { 0 , 1 } ) {
		if (bezeichnung.at(0) < 'G' && bezeichnung.at(1) > ('0' + i) && bezeichnung.at(1) < ('8' + i))
		{// Right : Up and Down
			string x = "  ";
			x.at(0) = bezeichnung.at(0) + 2;
			x.at(1) = bezeichnung.at(1) + (1 - (i + i));

			if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ' || this->farbe != s.get_Spielstand()[x].get_Figur()->get_Farbe())
			{
				springerV.push_back(x);
			}
		}
		if (bezeichnung.at(1) < '7' && bezeichnung.at(0) >= ('A' + i) && bezeichnung.at(0) < ('H' + i))
		{// Up : Left and Right
			string x = "  ";
			x.at(0) = bezeichnung.at(0) + (1 - (i + i));
			x.at(1) = bezeichnung.at(1) + 2;

			if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ' || this->farbe != s.get_Spielstand()[x].get_Figur()->get_Farbe())
			{
				springerV.push_back(x);
			}
		}
		
		if (bezeichnung.at(0) > 'B' && bezeichnung.at(1) > ('0' + i) && bezeichnung.at(1) < ('8' + i))
		{// Left : Up and Down
			string x = "  ";
			x.at(0) = bezeichnung.at(0) - 2;
			x.at(1) = bezeichnung.at(1) + (1 - (i + i));

			if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ' || this->farbe != s.get_Spielstand()[x].get_Figur()->get_Farbe())
			{
				springerV.push_back(x);
			}
		}
		if (bezeichnung.at(1) > '2' && bezeichnung.at(0) >= ('A' + i) && bezeichnung.at(0) < ('H' + i))
		{// Down : Left and Right
			string x = "  ";
			x.at(0) = bezeichnung.at(0) + (1 - (i + i));
			x.at(1) = bezeichnung.at(1) - 2;

			if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ' || this->farbe != s.get_Spielstand()[x].get_Figur()->get_Farbe())
			{
				springerV.push_back(x);
			}
		}
	}
	
	/* Convert vector<string> into vector<Feld> */
	vector<Feld> felder;
	for (string& str : springerV)
	{
		felder.push_back(s.get_Spielstand().at(str));
	}

	// Return
	return felder;
}

