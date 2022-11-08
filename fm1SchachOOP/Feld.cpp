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
		figur = new Bauer(); 
		break;
	case 'T': case 't':
		figur = new Turm();
		break;
	case 'L': case 'l':
		figur = new Laeufer();
		break;
	default:
		figur = new Leer();
		break;
	}

	




}
