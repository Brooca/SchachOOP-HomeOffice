#pragma once
using namespace std;
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

//! Inclusion in cause of Komposition
class Feld;

//! Figur -----------------------------------------------------------

class Figur
{
protected:
	bool farbe;
	unsigned char bezeichnung;
public:
	bool get_Farbe();
	unsigned char get_Bezeichnung();
	virtual vector<Feld> erlaubteFelderBerechnen(string);
};


//! FELD ___________________________________________________________
#include "Bauer.h"
#include "Dame.h"
#include "Koenig.h"
#include "Laeufer.h"
#include "Leer.h"
#include "Springer.h"
#include "Turm.h"

#include "Spiel.h"

class Feld
{
private:
	string bezeichnung;
	bool feldFarbe;
	Figur* figur;
	vector<Feld> erlaubteFelder;
public:
	Feld();
	Feld(string);
	Feld(string, char);
	vector<Feld> get_ErlaubteFelder();
	string get_Bezeichnung();
	Figur* get_Figur();
	void set_ErlaubteFelder(string);
};