#include "Spieler.h"

//! Konstruktoren
Spieler::Spieler() {}
Spieler::Spieler(string n, bool f) : name(n), spielerFarbe(f) {}

//! Getter & Setter
string Spieler::get_Name()	{	return name;	}
bool Spieler::get_Farbe()	{	return spielerFarbe;	}

//! Methoden
ostream& operator << (ostream& lhs, Spieler& rhs) {
	lhs << rhs.get_Name() << "\n";
	return lhs;
}