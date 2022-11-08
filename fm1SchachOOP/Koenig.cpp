#include "Koenig.h"

Koenig::Koenig(bool symbol)
{
	std::cout << "Koenig instanziert\n";
	farbe = symbol;
	bezeichnung = (symbol) ? 'B' : 'b';
	std::cout << "symbol : " << symbol << std::endl;
	std::cout << "bezeichnung : " << bezeichnung << std::endl;
}
