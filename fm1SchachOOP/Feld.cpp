#include "FeldFigur.h"

Feld::Feld()
{
}

Feld::Feld(string bez)
{
	bezeichnung = bez;
}

Feld::Feld(string bez, char symbol)
{
	// Bezeichnung von Feld
	bezeichnung = bez;

	// Figur* auf Feld setzen
	switch (symbol)
	{
	case 'B': case 'b':
		figur = new Bauer(islower(symbol));
		break;
	case 'T': case 't':
		figur = new Turm(islower(symbol));
		break;
	case 'L': case 'l':
		figur = new Laeufer(islower(symbol));
		break;
	case 'S': case 's':
		figur = new Springer(islower(symbol));
		break;
	case 'D': case 'd':
		figur = new Dame(islower(symbol));
		break;
	case 'K': case 'k':
		figur = new Koenig(islower(symbol));
		break;
	default:
		figur = new Leer(bez);
		break;
	}
}

vector<Feld> Feld::get_ErlaubteFelder()
{
	return erlaubteFelder;
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
	erlaubteFelder = figur->erlaubteFelderBerechnen(bezeichnung);
}