#pragma once
#include <string>
#include <iostream>
using namespace std;

class Spieler
{
private:
	string name;
	bool spielfarbe;
public:
	Spieler();
	Spieler(string, bool);
	friend ostream& operator << (ostream& lhs, array<Spieler, 2> rhs);
};

