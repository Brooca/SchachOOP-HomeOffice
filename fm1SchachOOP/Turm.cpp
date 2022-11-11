#include "Turm.h"
#include <string>
#include <vector>
using namespace std;

Turm::Turm(bool symbol) {
	farbe = symbol;
	bezeichnung = (symbol) ? 'T' : 't';
}

std::vector<std::string> Turm::erlaubteFelderBerechnen(std::string bezeichnung)
{
	vector<string>TurmV;
	for (int i = 0; i < 8; i++)
	{
		for(int k = 7; k >= 0; k--)
												//Erster durchlauf 
		{
		if (bezeichnung.at(0) == (65 + i))		// A + 0  
			{
			string x = "  ";
				cout << " ";
				x.at(0) = bezeichnung.at(0) + k - i; // A + 7 / A + 6 
				x.at(1) = bezeichnung.at(1);
				TurmV.push_back(x);
				cout << " " << TurmV.at(TurmV.size() - 1);
			}
			if (bezeichnung.at(1) == (49 + i))
			{
				string x = "  ";
				cout << " ";
				x.at(0) = bezeichnung.at(0) ;
				x.at(1) = bezeichnung.at(1) + k - i;
				TurmV.push_back(x);
				cout << " " << TurmV.at(TurmV.size() - 1);
			}
		}
	}

	return TurmV;
}
