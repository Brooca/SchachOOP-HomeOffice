#pragma once
#include <string>
#include "Figur.h"
class Feld
{
private:
	std::string bezeichnung;
	// bool feldFarbe;
	Figur* figur;
	// erlaubte Felder
public:
	Feld(); 
	Feld(std::string);
	Feld(std::string, char);
	std::string get_Bezeichnung();
	Figur* get_Figur();
};

