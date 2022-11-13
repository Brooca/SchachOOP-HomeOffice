#include "Laeufer.h"
#include <iostream>
#include <string>
using namespace std;

Laeufer::Laeufer()
{
	std::cout << "Laeufer erstellt\n";
}

Laeufer::Laeufer(bool symbol) {
	farbe = symbol;
	bezeichnung = (symbol) ? 'L' : 'l';
}

std::vector<std::string> Laeufer::erlaubteFelderBerechnen(std::string bezeichnung)
{
	// Output
	cout << "std::vector<std::string> Laeufer::erlaubteFelderBerechnen(std::string bezeichnung)\n";
	std::cout << "Erlaubte Felder von Laeufer auf " << bezeichnung << " :";

	// Test - Value
	cout << "X1 X2 X3";
	return {"X1","X2","X3"};
}
