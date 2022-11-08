#include "Turm.h"
Turm::Turm(bool symbol) {
	farbe = symbol;  // true or false 
	std::cout << "Farbe Turm : " << farbe << std::endl;

	bezeichnung = (symbol) ? 'T' : 't';
	std::cout << "bezeichnung : " << bezeichnung << std::endl;
}