#include "Turm.h"
#include <vector>
#include <string>
using namespace std;

Turm::Turm()
{
}

Turm::Turm(bool symbol) {
	farbe = symbol;
	bezeichnung = (symbol) ? 'T' : 't';
}

std::vector<std::string> Turm::erlaubteFelderBerechnen(std::string bezeichnung)
{
	// Calculation
	vector<string>TurmV;
	for (int i = 0; i < 8; i++)
	{
		for(int k = 7; k >= 0; k--)
		{
		if (bezeichnung.at(0) == (65 + i))
			{
			string x = "  ";
				cout << " ";
				x.at(0) = bezeichnung.at(0) + k - i;
				x.at(1) = bezeichnung.at(1);
				if (x.at(0) != (65 + i))
				{
					TurmV.push_back(x);
				}
			}
			if (bezeichnung.at(1) == (49 + i))
			{
				string x = "  ";
				cout << " ";
				x.at(0) = bezeichnung.at(0) ;
				x.at(1) = bezeichnung.at(1) + k - i;
				if (x.at(1) != (49 + i))
				{
					TurmV.push_back(x);
				}
			}
		}
	}
	return TurmV;
}
