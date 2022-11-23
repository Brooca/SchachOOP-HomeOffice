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
		for (int k = 7; k >= 0; k--)
		{
			// Berechnung der horizontal erlaubten Felder								// erster durchlauf der aeusseren Schleife								//letzter durchlauf der aeusseren Schleife
			if (bezeichnung.at(0) == (65 + i))											// wenn Spielfigur auf A + 0 = A										// wenn Spielfigur auf A + 7 = H
			{
				string x = "  ";														// erster durchgang der inneren // letzte durchgang der inneren			// erster durchgang der inneren // letzte durchgang der inneren
				x.at(0) = bezeichnung.at(0) + k ;										// A + 7 - 0 = H		 		// A + 0 - 0 = A 						// H + 7 - 7 = H		 		// H + 0 - 7 = A 
				x.at(1) = bezeichnung.at(1);											// Zahl bleibt unverändert
				if (x.at(0) != (65 + i) && x.at(0) >= 65 && x.at(0) <= 72) 				// wenn die ausgerechnete zahl also A + k - i == A + i entspricht, dann nicht ausgeben  
				{																		// damit wird die Position excludiert, auf der die Figur steht
					TurmV.push_back(x);
				}
			}
			if (bezeichnung.at(0) == (65 + i))											// wenn Spielfigur auf A + 0 = A										// wenn Spielfigur auf A + 7 = H
			{
				string x = "  ";														// erster durchgang der inneren // letzte durchgang der inneren			// erster durchgang der inneren // letzte durchgang der inneren
				x.at(0) = bezeichnung.at(0)  - i;										// A + 7 - 0 = H		 		// A + 0 - 0 = A 						// H + 7 - 7 = H		 		// H + 0 - 7 = A 
				x.at(1) = bezeichnung.at(1);											// Zahl bleibt unverändert
				if (x.at(0) != (65 + i) && x.at(0) >= 65 && x.at(0) <= 72)				// wenn die ausgerechnete zahl also A + k - i == A + i entspricht, dann nicht ausgeben  
				{																		// damit wird die Position excludiert, auf der die Figur steht
					TurmV.push_back(x);
				}
			}
		}
	}
		for (int i = 0; i < 8; i++)
		{
			for (int k = 7; k >= 0; k--)
			{
		// Berechnung der vertikal erlaubten Felder										// erster durchlauf der aeusseren Schleife								//letzter durchlauf der aeusseren Schleife
			if (bezeichnung.at(1) == (49 + i))											// wenn Spielfigur auf 1 + 0 = 1										// wenn Spielfigur auf 1 + 7 = 8
			{	
				string x = "  ";														// erster durchgang der inneren // letzte durchgang der inneren			// erster durchgang der inneren // letzte durchgang der inneren
				x.at(0) = bezeichnung.at(0) ;											// Buchstabe bleibt unverändert
				x.at(1) = bezeichnung.at(1) + k ;										// 1 + 7 - 0 = 8		 		// 1 + 0 - 0 = 1 						// 8 + 7 - 7 = 8		 		// 8 + 0 - 7 = 1 
				if (x.at(0) != (49 + i) && x.at(0) >= 49 && x.at(0) <= 56)				// wenn die ausgerechnete zahl also 1 + k - i == 1 + i entspricht, dann nicht ausgeben 
				{																		// damit wird die Position excludiert, auf der die Figur steht
												
					TurmV.push_back(x);
				}
			}
			if (bezeichnung.at(1) == (49 + i))											// wenn Spielfigur auf 1 + 0 = 1										// wenn Spielfigur auf 1 + 7 = 8
			{
				string x = "  ";														// erster durchgang der inneren // letzte durchgang der inneren			// erster durchgang der inneren // letzte durchgang der inneren
				x.at(0) = bezeichnung.at(0);											// Buchstabe bleibt unverändert
				x.at(1) = bezeichnung.at(1)  - i;										// 1 + 7 - 0 = 8		 		// 1 + 0 - 0 = 1 						// 8 + 7 - 7 = 8		 		// 8 + 0 - 7 = 1 
				if (x.at(0) != (49 + i) && x.at(0) >= 49 && x.at(0) <= 56)				// wenn die ausgerechnete zahl also 1 + k - i == 1 + i entspricht, dann nicht ausgeben 
				{																		// damit wird die Position excludiert, auf der die Figur steht

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
