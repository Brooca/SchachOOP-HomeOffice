#include "Spiel.h"

Spiel::Spiel()
{
	std::string eingabe;
	// Spieler bestimmen
std::cout << "Bitte den ersten Spieler angeben, der weiss spielt\n";
	std::cin >> eingabe;
	Spieler spieler1(eingabe,1);
std::cout << "Bitte den zweiten Spieler angeben, der schwarz spielt\n";
	std::cin >> eingabe;
	Spieler spieler2(eingabe,0); 

	// spielstand map<string,Feld>   in Grundstellung mit Feldern f�llen
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

		system("Pause"); 

}