#include "Bauer.h"

Bauer::Bauer(bool symbol)
{
	// std::cout << "Bauer instanziert\n";
	farbe = symbol; // 1 is white
	bezeichnung = (symbol) ? 'B' : 'b';
	// std::cout << "symbol : " << symbol << std::endl;
	// std::cout << "bezeichnung : " << bezeichnung << std::endl;
}

