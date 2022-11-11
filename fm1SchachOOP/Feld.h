#pragma once
#include <string>
#include <vector>
#include "Figur.h"
class Feld
{
private:
	std::string bezeichnung;
	bool feldFarbe;
	Figur* figur;
	std::vector<std::string> erlaubteFelder;
public:
	Feld(); 
	Feld(std::string);
	Feld(std::string, char);
	std::string get_Bezeichnung();
	Figur* get_Figur();
	void set_ErlaubteFelder(std::string); //Parameter
};

