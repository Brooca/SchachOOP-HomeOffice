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
							LaeuferV.push_back(x);

						}
						else if (this->farbe == s.get_Spielstand()[x].get_Figur()->get_Farbe())
						{
							break;
						}
						else if (this->farbe != s.get_Spielstand()[x].get_Figur()->get_Farbe())
						{

							LaeuferV.push_back(x);
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
							LaeuferV.push_back(x);

						}
						else if (this->farbe == s.get_Spielstand()[x].get_Figur()->get_Farbe())
						{
							break;
						}
						else if (this->farbe != s.get_Spielstand()[x].get_Figur()->get_Farbe())
						{
							LaeuferV.push_back(x);
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
							LaeuferV.push_back(x);

						}
						else if (this->farbe == s.get_Spielstand()[x].get_Figur()->get_Farbe())
						{
							break;
						}
						else if (this->farbe != s.get_Spielstand()[x].get_Figur()->get_Farbe())
						{
							LaeuferV.push_back(x);
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

	// Links runter

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
							LaeuferV.push_back(x);

						}
						else if (this->farbe == s.get_Spielstand()[x].get_Figur()->get_Farbe())
						{
							break;
						}
						else if (this->farbe != s.get_Spielstand()[x].get_Figur()->get_Farbe())
						{
							LaeuferV.push_back(x);
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
	for (string& str : LaeuferV)
	{
		felder.push_back(s.get_Spielstand()[str]);
	}

	return felder;
}