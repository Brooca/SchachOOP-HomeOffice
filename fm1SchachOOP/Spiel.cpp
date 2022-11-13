#include "Spiel.h"

Spiel::Spiel()
{
	// User-Input: Array<string> spieler
	set_Spieler();

	// Key-String
	std::string figurenFolge = "TSLDKLSTBBBBBBBB";
	figurenFolge += std::string(32, ' ');
	figurenFolge += "bbbbbbbbtsldklst";
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
	// Output
	std::cout << endl << "void Spiel::ziehen()" << endl;

	// Test-Abruf Turm auf A1
	cout << endl << endl << "Test-Abruf Turm auf A1";
	spielstand["A1"].set_ErlaubteFelder("A1");

	// Test-Abruf Springer auf B1
	/*
	cout << endl << "Test-Abruf Springer auf B1";
	spielstand["B1"].set_ErlaubteFelder("B1");
	*/

	// Test-Abruf Laeufer auf C1
	cout << endl << endl << "Test-Abruf Laeufer auf C1";
	spielstand["C1"].set_ErlaubteFelder("C1");
}
