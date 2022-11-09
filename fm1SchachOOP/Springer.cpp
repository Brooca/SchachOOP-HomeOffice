#include "Springer.h"

Springer::Springer(bool symbol)
{
	// std::cout << "Springer instanziert\n";
	farbe = symbol;
	bezeichnung = (symbol) ? 'S' : 's';
	// std::cout << "symbol : " << symbol << std::endl;
	// std::cout << "bezeichnung : " << bezeichnung << std::endl;
}