#pragma once
#include "Spieler.h"
#include "Feld.h"
#include <iostream>
#include <array>
#include <vector>
#include <map>

class Spiel
{
private:
	std::array<Spieler, 2> spieler;
	
	// std::array<std::array<Feld, 8>, 8> spielstand;   // spielstand.at(zeile).at(spalte)
	// std::vector<Feld> spielstand;                    // spielstand.at(ausStringLaufendeNummer)
    std::map<string,Feld> spielstand;                // spielstand["zeilespalte"]
	

public:
	Spiel();
};

