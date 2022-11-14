#include "Spieler.h"

Spieler::Spieler()
{
}

Spieler::Spieler(string n, bool f) 
	    : name(n), spielfarbe(f)
{
	// std::cout << name << " spielt " << (f ? "weiss" : "schwarz") << "\n"; 
}

ostream& operator << (ostream& lhs, Spieler rhs) {
	lhs << "Spieler*in: " << rhs.get_Name() << "\n";
	return lhs;
}
