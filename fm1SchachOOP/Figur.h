#pragma once
#include <iostream>
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
	virtual std::vector<std::string> erlaubteFelderBerechnen(std::string);
};