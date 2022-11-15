#pragma once
using namespace std;
#include <string>
#include <iostream>
#include <array>

class Spieler
{
private:
	string name;
	bool spielfarbe;
public:
	Spieler();
	Spieler(string, bool);
	string get_Name();
	friend ostream& operator << (ostream& lhs, Spieler& rhs);
};

