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
	for(int n = 0; n < 2; n+2){
	for (int i = 0; i < 8; i++)
	{
		for (int k = 0; k < 8; k++)
		{
			// Berechnung der horizontal erlaubten Felder : Nach Recht ->								
			if (bezeichnung.at(0) == (65 + i))													// Feld auf dem man steht				| 65 + 0 = A 		
			{
				string x = "  ";														 
				x.at(0) = bezeichnung.at(0) + k - (k * n);												// Feld auf das man sich bewegen kann	| 65 + 0 = A 		
				x.at(1) = bezeichnung.at(1);													// vertikale bleibt unverändert		
				if (x.at(0) != (65 + i) && x.at(0) >= 65 && x.at(0) <= 72) 						// Felder auf dem man steht excludieren & nur on Board range erlauben		
				{	
					if(s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' '){			// Wenn das Feld leer ist, ist es erlaubt -> pushback																
						TurmV.push_back(x);
					
					}
					else if (this->farbe == s.get_Spielstand()[x].get_Figur()->get_Farbe()) {	// Wenn die Figur auf dem Feld die selbe Farbe hat als diese Figur kein pushback & break
						break;
					}
					else if (this->farbe != s.get_Spielstand()[x].get_Figur()->get_Farbe()) {	// Wenn die Figur auf dem Feld eine andere Farbe hat als diese Figur, ist es erlaubt -> pushback & danach break
						TurmV.push_back(x);
						break;
					}
				}
			}
		
		}
	}
	}
	/*
	for (int i = 0; i < 8; i++)
	{
		for (int k = 0; k < 8; k++)
		{
			// Berechnung der vertikal erlaubten Felder: Nach Oben ^												
			if (bezeichnung.at(1) == (49 + i))													
			{
				string x = "  ";																	
				x.at(0) = bezeichnung.at(0);											
				x.at(1) = bezeichnung.at(1) + k;															
				if (x.at(1) != (49 + i) && x.at(1) >= 49 && x.at(1) <= 56)				
				{
					if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ') {																	
						TurmV.push_back(x);

					}
						else if (this->farbe == s.get_Spielstand()[x].get_Figur()->get_Farbe()) {
							break;
						}
						else if (this->farbe != s.get_Spielstand()[x].get_Figur()->get_Farbe()) {
							TurmV.push_back(x);
							break;
						}
				}
			}
		}
	}*/
		for (int i = 0; i < 8; i++)
		{
			for (int k = 0; k < 8; k++)
			{
				// Berechnung der vertikal erlaubten Felder: Nach Unten V
			if (bezeichnung.at(1) == (49 + i))											
			{
				string x = "  ";														 
				x.at(0) = bezeichnung.at(0);											
				x.at(1) = bezeichnung.at(1)  - k;										
				if (x.at(1) != (49 + i) && x.at(1) >= 49 && x.at(1) <= 56)				 
				{
					if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ') {																	
						TurmV.push_back(x);

					}
						else if (this->farbe == s.get_Spielstand()[x].get_Figur()->get_Farbe()) {
							break;
						}
						else if (this->farbe != s.get_Spielstand()[x].get_Figur()->get_Farbe()) {
							TurmV.push_back(x);
							break;
						}
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
