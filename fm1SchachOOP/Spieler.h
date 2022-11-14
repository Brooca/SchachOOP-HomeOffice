#pragma once
#include <string>
#include <iostream>
#include <array>
using namespace std;

class Spieler
{
private:
	string name;
	bool spielfarbe;
public:
	Spieler();
	Spieler(string, bool);
	string get_Name() { return name; };
	friend ostream& operator << (ostream& lhs, Spieler rhs);
};

