#include "Dame.h"

Dame::Dame(bool symbol)
{
	farbe = symbol;
	bezeichnung = (symbol) ? 'D' : 'd';
	std::cout << "Farbe Dame: " << symbol << std::endl;
	std::cout << "bezeichnung : " << bezeichnung << std::endl;
}
