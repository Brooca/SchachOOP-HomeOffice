#include "Laeufer.h"
#include <iostream>
#include <string>
using namespace std;

Laeufer::Laeufer()
{
}

Laeufer::Laeufer(bool symbol) {
	farbe = symbol;
	bezeichnung = (symbol) ? 'L' : 'l';
}

std::vector<std::string> Laeufer::erlaubteFelderBerechnen(std::string bezeichnung)
{
	// Test - Value
	return {"X1","X2","X3"};
}
