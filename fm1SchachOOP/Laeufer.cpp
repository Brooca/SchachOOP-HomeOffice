#include "Laeufer.h"

Laeufer::Laeufer()
{
}

Laeufer::Laeufer(bool symbol) {
	farbe = symbol;
	bezeichnung = (symbol) ? 'L' : 'l';
}

vector<string> Laeufer::erlaubteFelderBerechnen(string bezeichnung)
{
	// Test - Value
	return {"X1","X2","X3"};
}
