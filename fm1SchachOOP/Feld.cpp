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
