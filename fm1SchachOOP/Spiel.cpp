#include "Spiel.h"

Spiel::Spiel()
{
	set_Spieler();

	// spielstand map<string,Feld>   in Grundstellung mit Feldern füllen
	// key strings erzeugen

	
	std::string figurenFolge = "TSLDKLSTBBBBBBBB";
	figurenFolge += std::string(32, ' '); 
	figurenFolge += "bbbbbbbbtslkdlst";
	int index = 0;
	
		for (char d = '1'; d <= '8'; d++)
		{
			for (char c = 'A'; c <= 'H'; c++)
			{
			// std::cout << c << d << "=" << figurenFolge[index++] << "\n"; 
			std::string key = std::string(1,c) + d; //  std::string(1,c1)+c2;
			spielstand[key] = Feld::Feld(key,figurenFolge[index++]); 
			}
		}

		// system("Pause"); 

}

map<string, Feld> Spiel::get_Spielstand()
{
	return spielstand;
}

void Spiel::set_Spieler()
{
	std::string eingabe;

	std::cout << "Spieler*in Weiss:   ";
	std::cin >> eingabe;
	Spieler spieler1(eingabe, 1);
	std::cout << "Spieler*in Schwarz: ";
	std::cin >> eingabe;
	Spieler spieler2(eingabe, 0);
	std::cout << "\n";
}
