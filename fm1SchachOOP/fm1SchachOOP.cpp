// fm1SchachOOP.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>

#include "Spiel.h"
#include "Anzeige.h"



int main()
{
	Spiel s;
	Anzeige::anzeigeSpielstand(s.get_Spielstand());

	system("Pause");
}