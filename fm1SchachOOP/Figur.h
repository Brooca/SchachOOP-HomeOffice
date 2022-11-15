#pragma once
using namespace std;
#include <string>
#include <vector>

class Figur
{
protected:
	bool farbe;
	char bezeichnung;
public:
	bool get_Farbe();
	char get_Bezeichnung();
	virtual vector<string> erlaubteFelderBerechnen(string);
};