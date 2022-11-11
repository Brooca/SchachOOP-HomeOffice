#include "Spiel.h"

Spiel::Spiel()
{
	// User-Input: Array<string> spieler
	set_Spieler();

	// Key-String
	std::string figurenFolge = "TSLDKLSTBBBBBBBB";
	figurenFolge += std::string(32, ' ');
	figurenFolge += "bbbbbbbbtslkdlst";
	int index = 0;
	
	/* spielstand map<string, Feld> : in Grundstellung mit Feldern füllen */
		for (char d = '1'; d <= '8'; d++)
		{
			for (char c = 'A'; c <= 'H'; c++)
			{
			std::string key = std::string(1,c) + d;
			spielstand[key] = Feld::Feld(key,figurenFolge[index++]); 
			}
		}
}

map<string, Feld> Spiel::get_Spielstand()
{
	return spielstand;
}

void Spiel::set_Spieler()
{
	std::string eingabe;

	// Spieler 1
	std::cout << "Spieler*in Weiss:   ";
	std::cin >> eingabe;
	Spieler spieler1(eingabe, 1);

	// Spieler 2
	std::cout << "Spieler*in Schwarz: ";
	std::cin >> eingabe;
	Spieler spieler2(eingabe, 0);
	std::cout << "\n";
}

void Spiel::ziehen()
{
	// hier sollen alle Felder aus der Map angesprochen werden
	std::cout << endl << "void Spiel::ziehen()" << endl;

	// Test-Abruf Springer auf B1 
	spielstand["B1"].set_ErlaubteFelder("B1");
}
