#pragma once
#include "Spieler.h"
#include "Feld.h"
#include <iostream>
#include <array>
#include <vector>
#include <map>
using namespace std;

class Spiel
{
private:
	std::array<Spieler, 2> spieler;
    std::map<string,Feld> spielstand;
public:
	Spiel();
	map<string, Feld> get_Spielstand();
	array<Spieler, 2> get_Spieler();
	void set_Spieler();
	void ziehen();
	friend ostream& operator << (ostream& lhs, Spiel& rhs);
};

