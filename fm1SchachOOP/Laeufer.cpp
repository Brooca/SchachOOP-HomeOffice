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
	
			for (int j = 0; j < 16; j++)
			{
				
					for (int i = 0; i < 16; i++)
					{
						
						
							if (abs(bezeichnung.at(0) - bezeichnung.at(1)) == abs((bezeichnung.at(0) - 8 + i) - (bezeichnung.at(1) - 8 + j)))
							{

								string x = "  ";
								x.at(0) = bezeichnung.at(0) - 8 + i;
								x.at(1) = bezeichnung.at(1) - 8  + j;
									
										
											
											 
												if (x.at(0) >= 65  && x.at(0) <= 72 && x.at(1) >= 49 && x.at(1) <= 56)
												{
													if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ')						
													{
														LaeuferV.push_back(x);

													}
													else if (this->farbe == s.get_Spielstand()[x].get_Figur()->get_Farbe())					
													{
														break;
													}
													else if (this->farbe != s.get_Spielstand()[x].get_Figur()->get_Farbe())					
													{
														LaeuferV.push_back(x);
														break;
													}
												}
											
						
									
							}
						
					}
				
			}	
			
		vector<Feld> felder;
		for (string& str : LaeuferV) {
			felder.push_back(s.get_Spielstand()[str]);
		}
	return felder;
}
/*vector<Feld> Turm::erlaubteFelderBerechnen(string bezeichnung)
{
	// Calculation
	vector<string> TurmV;
	for (int m = 0; m < 2; m++)
	{
		for (int n = 0; n < 3; n += 2)
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
								TurmV.push_back(x);

							}
							else if (this->farbe == s.get_Spielstand()[x].get_Figur()->get_Farbe())					// Wenn die Figur auf dem Feld die selbe Farbe hat als diese Figur kein pushback & break
							{
								break;
							}
							else if (this->farbe != s.get_Spielstand()[x].get_Figur()->get_Farbe())					// Wenn die Figur auf dem Feld eine andere Farbe hat als diese Figur, ist es erlaubt -> pushback & danach break
							{
								TurmV.push_back(x);
								break;
							}
						}
					}
				}
			}
		}
	}


	vector<Feld> felder;
	for (string& str : TurmV)
	{
		felder.push_back(s.get_Spielstand()[str]);
	}

	return felder;
}*/