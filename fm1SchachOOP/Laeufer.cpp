#include "Laeufer.h"
Laeufer::Laeufer(bool symbol) {
	// std::cout << "Laeufer instanziert\n";
	farbe = symbol;
	// std::cout << "symbol : " << symbol << std::endl;

	bezeichnung = (symbol) ? 'L' : 'l';
	// std::cout << "bezeichnung : " << bezeichnung << std::endl;
}
