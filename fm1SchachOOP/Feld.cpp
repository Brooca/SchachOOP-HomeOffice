#include "Feld.h"
#include "Bauer.h"
#include "Dame.h"
#include "Koenig.h"
#include "Laeufer.h"
#include "Leer.h"
#include "Springer.h"
#include "Turm.h"
#include <iostream>

using namespace std;

Feld::Feld()
{
	cout<<"Feld wird angelegt\n";

}

Feld::Feld(std::string bez)
{
	bezeichnung = bez;
	std::cout << "Feld " << bezeichnung << " wird angelegt\n";
}

Feld::Feld(std::string bez, char symbol)
{
	std::cout << "Feld " << bezeichnung << " wird mit " << symbol << " angelegt\n";
	bezeichnung = bez;
	// abhängig von symbol soll eine Figur des Typs über einen Zeiger in das Feld gesetzt werden

	switch (symbol)
	{
	case 'B': case 'b':
		figur = new Bauer(isupper(symbol)); // mach mir Bauer(true false // isupper ?? B b)
		// erlaubteFelder =
		break;
	case 'T': case 't':
		figur = new Turm(isupper(symbol));  // T oder t ??
		break;
	case 'L': case 'l':
		figur = new Laeufer(isupper(symbol));
		break;
	case 'S': case 's':
		figur = new Springer(isupper(symbol));
		// Rechts hoch
		cout << bezeichnung.at(0);
		cout << bezeichnung.at(1);
		if (bezeichnung.at(0) < 71  && bezeichnung.at(1) > 48 && bezeichnung.at(1) < 56)
		{
			string x = "  ";
			cout << "----------------";
			x.at(0) = bezeichnung.at(0) + 2;
			x.at(1) = bezeichnung.at(1) + 1;
			this->erlaubteFelder.push_back(x);
			cout << "---------------" << erlaubteFelder.at(erlaubteFelder.size()-1);
		}

		//Rechts runter
		 if (bezeichnung.at(0) < 71 && bezeichnung.at(1) > 49 && bezeichnung.at(1) < 57)
		{
			string x = "  ";
			cout << "----------------";
			x.at(0) = bezeichnung.at(0) + 2;
			x.at(1) = bezeichnung.at(1) - 1;
			this->erlaubteFelder.push_back(x);
			cout << "---------------" << erlaubteFelder.at(erlaubteFelder.size() - 1);
		}

		//links hoch
		 if (bezeichnung.at(0) > 66 && bezeichnung.at(1) > 48 && bezeichnung.at(1) < 56)
		{
				string x = "  ";
			cout << "----------------";
			x.at(0) = bezeichnung.at(0) - 2;
			x.at(1) = bezeichnung.at(1) + 1;
			this->erlaubteFelder.push_back(x);
			cout << "---------------" << erlaubteFelder.at(erlaubteFelder.size() - 1);
		}
		
		//links runter
		 if (bezeichnung.at(0) > 66 && bezeichnung.at(1) > 49 && bezeichnung.at(1) < 57)
		{
				string x = "  ";
			cout << "----------------";
			x.at(0) = bezeichnung.at(0) - 2;
			x.at(1) = bezeichnung.at(1) - 1;
			this->erlaubteFelder.push_back(x);
			cout << "---------------" << erlaubteFelder.at(erlaubteFelder.size() - 1);
		}

		// Hoch rechts
		 if (bezeichnung.at(1) < 55 && bezeichnung.at(0) > 64 && bezeichnung.at(0) < 72)
		{
				string x = "  ";
			cout << "----------------";
			x.at(0) = bezeichnung.at(0) + 1;
			x.at(1) = bezeichnung.at(1) + 2;
			this->erlaubteFelder.push_back(x);
			cout << "---------------" << erlaubteFelder.at(erlaubteFelder.size() - 1);
		}
		
		//Hoch links
		 if (bezeichnung.at(1) < 55 && bezeichnung.at(0) > 65 && bezeichnung.at(0) < 73)
		{
				string x = "  ";
			cout << "----------------";
			x.at(0) = bezeichnung.at(0) - 1;
			x.at(1) = bezeichnung.at(1) + 2;
			this->erlaubteFelder.push_back(x);
			cout << "---------------" << erlaubteFelder.at(erlaubteFelder.size() - 1);
		}
		
		//Runter rechts
		 if (bezeichnung.at(1) > 50 && bezeichnung.at(0) > 64 && bezeichnung.at(0) < 72)
		{
			
				string x = "  ";
			cout << "----------------";
			x.at(0) = bezeichnung.at(0) + 1;
			x.at(1) = bezeichnung.at(1) - 2;
			this->erlaubteFelder.push_back(x);
			cout << "---------------" << erlaubteFelder.at(erlaubteFelder.size() - 1);
		}
		
		//Runter links
		 if (bezeichnung.at(1) > 50 && bezeichnung.at(0) > 65 && bezeichnung.at(0) < 73)
		{
				string x = "  ";
			cout << "----------------";
			x.at(0) = bezeichnung.at(0) - 1;
			x.at(1) = bezeichnung.at(1) - 2;
			this->erlaubteFelder.push_back(x);
			cout << "---------------" << erlaubteFelder.at(erlaubteFelder.size() - 1);
		} 
		break;
	case 'D': case 'd':
		figur = new Dame(isupper(symbol));
		break;
	case 'K': case 'k':
		figur = new Koenig(isupper(symbol));
		break;
	default:
		figur = new Leer();
		break;
	}





}


/*
c = A d = 1

	c + 2 & d +1 || c + 2 & d - 1 
|| c - 2 & d + 1 || c - 2 & d - 1
|| d + 2 & c + 1 || d + 2 & c - 1 
|| d + 2 & c + 1 || d + 2 & c - 1 */