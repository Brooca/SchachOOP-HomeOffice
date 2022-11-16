#pragma once
using namespace std;
#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <string>

#include "Spieler.h"
#include "Feld.h"

class Spiel
{
private:
	array<Spieler, 2> spieler;
    map<string,Feld> spielstand;
public:
	Spiel();
	map<string, Feld> get_Spielstand();
	array<Spieler, 2> get_Spieler();
	void set_Spieler();
	void ziehen();
	friend ostream& operator << (ostream& lhs, Spiel& rhs);
};

