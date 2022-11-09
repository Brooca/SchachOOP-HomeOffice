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
	// cout<<"Feld wird angelegt\n";

}

Feld::Feld(std::string bez)
{
	bezeichnung = bez;
	// std::cout << "Feld " << bezeichnung << " wird angelegt\n";
}

Feld::Feld(std::string bez, char symbol)
{
	// std::cout << "Feld " << bezeichnung << " wird mit " << symbol << " angelegt\n";
	bezeichnung = bez;
	// abhängig von symbol soll eine Figur des Typs über einen Zeiger in das Feld gesetzt werden

	switch (symbol)
	{
	case 'B': case 'b':
		figur = new Bauer(isupper(symbol)); // mach mir Bauer(true false // isupper ?? B b)
		break;
	case 'T': case 't':
		figur = new Turm(isupper(symbol));  // T oder t ??
		break;
	case 'L': case 'l':
		figur = new Laeufer(isupper(symbol));
		break;
	case 'S': case 's':
		figur = new Springer(isupper(symbol));
		
		cout << "\nSpringer: ";
		cout << bezeichnung.at(0);
		cout << bezeichnung.at(1);
		cout << " Erlaubte Felder ";
		
		// Kleinste variante (kleine fehler)
		/*
		for (int i = 0; i < 2; i++) {
			for (int k = 0; k < 2; k++) {
				// Rechts hoch
				if (bezeichnung.at(0+k) < (71 - (6 * k)) && bezeichnung.at(1-k) > (48 + i + (6 * k)) && bezeichnung.at(1) < (56 + i + (6 * k)))
				{
					string x = "  ";
					cout << " ";
					x.at(0 + k) = bezeichnung.at(0 + k) + 2;
					x.at(1 - k) = bezeichnung.at(1 - k) + (1 - (i + i));
					this->erlaubteFelder.push_back(x);
					cout << " " << erlaubteFelder.at(erlaubteFelder.size() - 1);
				}
			
			if (bezeichnung.at(0+k) > (66-(16*k)) && bezeichnung.at(1 - k) > (48 + i +(6*k)) && bezeichnung.at(1) < (56 + i+(6*k)))
			{
				string x = "  ";
				x.at(0+k) = bezeichnung.at(0+k) - 2;
				x.at(1-k) = bezeichnung.at(1-k) + (1 - (i + i));
				this->erlaubteFelder.push_back(x);
				cout << " " << erlaubteFelder.at(erlaubteFelder.size() - 1);
			}
		
			}
		}*/
		// komprimierte Variante
		for (int i = 0; i < 2; i++) {
			if (bezeichnung.at(0) < 71 && bezeichnung.at(1) > (48 + i) && bezeichnung.at(1) < (56 + 1))
			{
				string x = "  ";
				cout << " ";
				x.at(0) = bezeichnung.at(0) + 2;
				x.at(1) = bezeichnung.at(1) + (1 - (i + i));
				this->erlaubteFelder.push_back(x);
				cout << " " << erlaubteFelder.at(erlaubteFelder.size() - 1);
			}
			if (bezeichnung.at(1) < 55 && bezeichnung.at(0) > (64 + i) && bezeichnung.at(0) < (72 + i))
			{
				string x = "  ";
				x.at(0) = bezeichnung.at(0) + (1 - (i + i));
				x.at(1) = bezeichnung.at(1) + 2;
				this->erlaubteFelder.push_back(x);
				cout << " " << erlaubteFelder.at(erlaubteFelder.size() - 1);
			}
			if (bezeichnung.at(0) > 66 && bezeichnung.at(1) > (48 + i) && bezeichnung.at(1) < (56 + i))
			{
				string x = "  ";
				x.at(0) = bezeichnung.at(0) - 2;
				x.at(1) = bezeichnung.at(1) + (1 - (i + i));
				this->erlaubteFelder.push_back(x);
				cout << " " << erlaubteFelder.at(erlaubteFelder.size() - 1);
			}
			if (bezeichnung.at(1) > 50 && bezeichnung.at(0) > (64 + i) && bezeichnung.at(0) < (72 + i))
			{

				string x = "  ";
				x.at(0) = bezeichnung.at(0) + (1 - (i + i));
				x.at(1) = bezeichnung.at(1) - 2;
				this->erlaubteFelder.push_back(x);
				cout << " " << erlaubteFelder.at(erlaubteFelder.size() - 1);
			}
		}
		break;
	case 'D': case 'd':
		figur = new Dame(isupper(symbol));
		break;
	case 'K': case 'k':
		figur = new Koenig(isupper(symbol));
		break;
	default:
		figur = new Leer(bez);
		break;
	}





}

string Feld::get_Bezeichnung()
{
	return bezeichnung;
}

Figur* Feld::get_Figur()
{
	return figur;
}


/*
c = A d = 1

	c + 2 & d +1 || c + 2 & d - 1 
|| c - 2 & d + 1 || c - 2 & d - 1
|| d + 2 & c + 1 || d + 2 & c - 1 
|| d + 2 & c + 1 || d + 2 & c - 1 */