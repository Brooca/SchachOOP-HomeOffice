#pragma once
using namespace std;
#include <string>
#include <iostream>
#include <array>

class Spieler
{	
	friend ostream& operator << (ostream& lhs, Spieler& rhs);

private:
	string name;
	bool spielerFarbe;
public:
	Spieler();
	Spieler(string, bool);
	string get_Name();
	bool get_Farbe();
};

