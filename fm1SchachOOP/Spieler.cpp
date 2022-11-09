#include "Spieler.h"

Spieler::Spieler()
{
}

Spieler::Spieler(string n, bool f) 
	    : name(n), spielfarbe(f)
{
	// std::cout << name << " spielt " << (f ? "weiss" : "schwarz") << "\n"; 
}
