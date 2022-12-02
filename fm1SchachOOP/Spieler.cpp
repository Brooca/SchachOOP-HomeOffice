#include "Spieler.h"

Spieler::Spieler()
{
}

Spieler::Spieler(string n, bool f) 
	    : name(n), spielerFarbe(f)
{
	// std::cout << name << " spielt " << (f ? "weiss" : "schwarz") << "\n"; 
}

string Spieler::get_Name()
{
	return name;
}


ostream& operator << (ostream& lhs, Spieler& rhs) {
	lhs << rhs.get_Name() << "\n";
	return lhs;
}

bool Spieler::get_Farbe()
{
	return spielerFarbe;
}