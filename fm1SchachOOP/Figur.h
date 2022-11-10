#pragma once
#include <iostream>
#include <string>
#include <vector>
class Figur
{
private:
protected:
	bool farbe;
	char bezeichnung;
public:
	bool get_Farbe();
	char get_Bezeichnung();

	// FELD :: vector<string>erlaubte Felder <- virtuelle Methode erlaubteFelderBerechnen()
	virtual std::vector<std::string> erlaubteFelderBerechnen() = 0;
};