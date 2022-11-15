#pragma once
using namespace std;
#include <string>
#include <vector>

#include "Bauer.h"
#include "Dame.h"
#include "Koenig.h"
#include "Laeufer.h"
#include "Leer.h"
#include "Springer.h"
#include "Turm.h"
#include "Figur.h"

class Feld
{
private:
	string bezeichnung;
	bool feldFarbe;
	Figur* figur;
	vector<string> erlaubteFelder;
public:
	Feld(); 
	Feld(string);
	Feld(string, char);
	vector<string> get_ErlaubteFelder();
	string get_Bezeichnung();
	Figur* get_Figur();
	void set_ErlaubteFelder(string);
};

