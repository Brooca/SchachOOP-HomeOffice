#include "Koenig.h"

extern Spiel s;
Koenig::Koenig(bool symbol)
{
	farbe = symbol;
	bezeichnung = (symbol) ? 'K' : 'k';
}

vector<Feld> Koenig::erlaubteFelderBerechnen(string bezeichnung)
{

	// Calculation Horizontal/ Vertikal
	vector<string> KoenigV;
	for (int m = 0; m < 2; m++)						// 0 = horizonal; 1 = vertikal
	{
		for (int n = 0; n < 3; n += 2)				// 0 = Horizontal Links & vertikal runter; 2 = Horizontal rechts & vertikal hoch
		{
			for (int i = 0; i < 8; i++)
			{

				// Berechnung der erlaubten Felder 								
				if (bezeichnung.at(m) == (65 + i - (16 * m)))			// m = 0; i = 2; C									// Feld auf dem man steht				| 65 + 0 = A 		
				{
					string x = "  ";
					x.at(m) = bezeichnung.at(m) + 1 - (1 * n);			//schreiben in erste stelle des string -> C + 1	= D -> D wird an erste stelle geschrieben											
					x.at(1 - m) = bezeichnung.at(1 - m);				// 5 bleibt 5 -> kommt an zweite stelle																	
					if (x.at(m) != (65 + i - (16 * m)) && x.at(m) >= 65 - (16 * m) && x.at(m) <= 72 - (16 * m))								// Felder auf dem man steht excludieren & nur on Board range erlauben		
					{//  D		!=  C				   && D		  >= A			   && D		  <= H	
						if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ')													// Wenn das Feld leer ist, ist es erlaubt -> pushback
						{
							KoenigV.push_back(x);

						}
						else if (this->farbe == s.get_Spielstand()[x].get_Figur()->get_Farbe())												// Wenn die Figur auf dem Feld die selbe Farbe hat als diese Figur kein pushback & break
						{
							break;
						}
						else if (this->farbe != s.get_Spielstand()[x].get_Figur()->get_Farbe())												// Wenn die Figur auf dem Feld eine andere Farbe hat als diese Figur, ist es erlaubt -> pushback & danach break
						{
							KoenigV.push_back(x);
							break;
						}
					}
				}

			}
		}
	}
		// Rechts hoch 
		bool erlaubnis = true;

		for (int i = 1; i < 8; i++)
		{
			if (erlaubnis == true)
			{


				for (int k = 1; k < 8; k++)
				{

					if (abs(bezeichnung.at(0) - bezeichnung.at(0) + i) == abs(bezeichnung.at(1) - bezeichnung.at(1) + k))
					{

						string x = "  ";
						x.at(0) = bezeichnung.at(0) + i;
						x.at(1) = bezeichnung.at(1) + k;




						if (x.at(0) >= 65 && x.at(0) <= 72 && x.at(1) >= 49 && x.at(1) <= 56)
						{
							if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ')
							{
								KoenigV.push_back(x);
								erlaubnis = false;
								break;
							}
							else if (this->farbe == s.get_Spielstand()[x].get_Figur()->get_Farbe())
							{
								erlaubnis = false;
								break;
							}
							else if (this->farbe != s.get_Spielstand()[x].get_Figur()->get_Farbe())
							{

								KoenigV.push_back(x);
								erlaubnis = false;
								break;
							}
						}
					}

				}
			}
			else
			{
				break;
			}
		}





		// Links Runter
		erlaubnis = true;

		for (int i = 1; i < 8; i++)
		{
			if (erlaubnis == true)
			{

				for (int k = 1; k < 8; k++)
				{
					if (abs(bezeichnung.at(0) - bezeichnung.at(0) - i) == abs(bezeichnung.at(1) - bezeichnung.at(1) - k))
					{

						string x = "  ";
						x.at(0) = bezeichnung.at(0) - i;
						x.at(1) = bezeichnung.at(1) - k;




						if (x.at(0) >= 65 && x.at(0) <= 72 && x.at(1) >= 49 && x.at(1) <= 56)
						{
							if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ')
							{
								KoenigV.push_back(x);
								erlaubnis = false;
								break;
							}
							else if (this->farbe == s.get_Spielstand()[x].get_Figur()->get_Farbe())
							{
								erlaubnis = false;
								break;
							}
							else if (this->farbe != s.get_Spielstand()[x].get_Figur()->get_Farbe())
							{
								KoenigV.push_back(x);
								erlaubnis = false;
								break;
							}
						}



					}
				}
			}
			else
			{
				break;
			}
		}

		// Rechts runter

		erlaubnis = true;

		for (int i = 1; i < 8; i++)
		{
			if (erlaubnis == true)
			{

				for (int k = 1; k < 8; k++)
				{
					if (abs(bezeichnung.at(0) - bezeichnung.at(0) + i) == abs(bezeichnung.at(1) - bezeichnung.at(1) - k))
					{

						string x = "  ";
						x.at(0) = bezeichnung.at(0) + i;
						x.at(1) = bezeichnung.at(1) - k;




						if (x.at(0) >= 65 && x.at(0) <= 72 && x.at(1) >= 49 && x.at(1) <= 56)
						{
							if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ')
							{
								KoenigV.push_back(x);
								erlaubnis = false;
								break;
							}
							else if (this->farbe == s.get_Spielstand()[x].get_Figur()->get_Farbe())
							{
								erlaubnis = false;
								break;
							}
							else if (this->farbe != s.get_Spielstand()[x].get_Figur()->get_Farbe())
							{
								KoenigV.push_back(x);
								erlaubnis = false;
								break;
							}
						}



					}
				}
			}
			else
			{
				break;
			}
		}

		// Links hoch

		erlaubnis = true;

		for (int i = 1; i < 8; i++)
		{
			if (erlaubnis == true) {

				for (int k = 1; k < 8; k++)
				{
					if (abs(bezeichnung.at(0) - bezeichnung.at(0) - i) == abs(bezeichnung.at(1) - bezeichnung.at(1) + k))
					{

						string x = "  ";
						x.at(0) = bezeichnung.at(0) - i;
						x.at(1) = bezeichnung.at(1) + k;




						if (x.at(0) >= 65 && x.at(0) <= 72 && x.at(1) >= 49 && x.at(1) <= 56)
						{
							if (s.get_Spielstand()[x].get_Figur()->get_Bezeichnung() == ' ')
							{
								KoenigV.push_back(x);
								erlaubnis = false;
								break;
							}
							else if (this->farbe == s.get_Spielstand()[x].get_Figur()->get_Farbe())
							{
								erlaubnis = false;
								break;
							}
							else if (this->farbe != s.get_Spielstand()[x].get_Figur()->get_Farbe())
							{
								KoenigV.push_back(x);
								erlaubnis = false;
								break;
							}
						}



					}
				}
			}
			else
			{
				break;
			}
		
	}
	vector<Feld> felder;
	for (string& str : KoenigV)
	{
		felder.push_back(s.get_Spielstand()[str]);
	}

	return felder;

}
