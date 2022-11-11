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
    std::map<string,Feld> spielstand;
	
public:
	Spiel();
	map<string, Feld> get_Spielstand();
	void set_Spieler();
	void ziehen();
};

