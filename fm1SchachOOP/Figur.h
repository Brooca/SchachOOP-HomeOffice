#pragma once
using namespace std;
#include <string>
#include <vector>

class Figur
{
protected:
	bool farbe;
	unsigned char bezeichnung;
public:
	bool get_Farbe();
	unsigned char get_Bezeichnung();
	virtual vector<string> erlaubteFelderBerechnen(string);
};