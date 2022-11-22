#include "Springer.h"

Springer::Springer(bool symbol)
{
	farbe = symbol;
	bezeichnung = (symbol) ? 'S' : 's';
}

std::vector<Feld> Springer::erlaubteFelderBerechnen(std::string bezeichnung)
{ 
	// Bewegungsmuster : Springer
	/* c = A d = 1
	|| c + 2 & d +1 || c + 2 & d - 1
	|| c - 2 & d + 1 || c - 2 & d - 1
	|| d + 2 & c + 1 || d + 2 & c - 1
	|| d + 2 & c + 1 || d + 2 & c - 1 */
	// Calculation
	/*vector<string>springerV;

	for (int i = 0; i < 2; i++) {	
		if (bezeichnung.at(0) < 71 && bezeichnung.at(1) > (48 + i) && bezeichnung.at(1) < (56 + i))
		{
			string x = "  ";
			x.at(0) = bezeichnung.at(0) + 2;
			x.at(1) = bezeichnung.at(1) + (1 - (i + i));
			springerV.push_back(x);
		}
		if (bezeichnung.at(1) < 55 && bezeichnung.at(0) > (64 + i) && bezeichnung.at(0) < (72 + i))
		{
			string x = "  ";
			x.at(0) = bezeichnung.at(0) + (1 - (i + i));
			x.at(1) = bezeichnung.at(1) + 2;
			springerV.push_back(x);
		}
		if (bezeichnung.at(0) > 66 && bezeichnung.at(1) > (48 + i) && bezeichnung.at(1) < (56 + i))
		{
			string x = "  ";
			x.at(0) = bezeichnung.at(0) - 2;
			x.at(1) = bezeichnung.at(1) + (1 - (i + i));
			springerV.push_back(x);
		}
		if (bezeichnung.at(1) > 50 && bezeichnung.at(0) > (64 + i) && bezeichnung.at(0) < (72 + i))
		{
			string x = "  ";
			x.at(0) = bezeichnung.at(0) + (1 - (i + i));
			x.at(1) = bezeichnung.at(1) - 2;
			springerV.push_back(x);
		}
	}
	return springerV;*/
	return {};
}

