#include "Turm.h"
Turm::Turm(bool symbol) {
	farbe = symbol;  // true or false 
	bezeichnung = (symbol) ? 'T' : 't';
	// std::cout << "Farbe Turm : " << symbol << std::endl;
	// std::cout << "bezeichnung : " << bezeichnung << std::endl;
}