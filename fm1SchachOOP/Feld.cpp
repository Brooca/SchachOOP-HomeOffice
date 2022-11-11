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
	// Bezeichnung von Feld
	bezeichnung = bez;

	// Figur* auf Feld setzen
	switch (symbol)
	{
	case 'B': case 'b':
		figur = new Bauer(isupper(symbol));
		break;
	case 'T': case 't':
		figur = new Turm(isupper(symbol));
		break;
	case 'L': case 'l':
		figur = new Laeufer(isupper(symbol));
		break;
	case 'S': case 's':
		figur = new Springer(isupper(symbol));
		
		/*
		cout << "\nSpringer: ";
		cout << bezeichnung.at(0);
		cout << bezeichnung.at(1);
		cout << " Erlaubte Felder ";
		*/

		// Rechts hoch
		
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

void Feld::set_ErlaubteFelder(string bezeichnung)
{
	// Output - Where am I ?
	cout  << endl << "void Feld::set_ErlaubteFelder(string bezeichnung)" << endl;

	// map<string,feld> -- feld.erlaubteFelder vector<string> <- erlaubteFelder Berechnen rein
	erlaubteFelder = figur->erlaubteFelderBerechnen(bezeichnung);
	// Push back bei mehrfach vererbung oder insert oder in --> dame neuer vector
}


/* Bewegungsmuster : Springer
c = A d = 1

	c + 2 & d +1 || c + 2 & d - 1 
|| c - 2 & d + 1 || c - 2 & d - 1
|| d + 2 & c + 1 || d + 2 & c - 1 
|| d + 2 & c + 1 || d + 2 & c - 1 */