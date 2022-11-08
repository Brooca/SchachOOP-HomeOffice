#include "Dame.h"

Dame::Dame(bool f)
{
	farbe = f;
	std::cout << "Farbe Dame: " << f << std::endl;

	bezeichnung = (f) ? 'D' : 'd';
	std::cout << "bezeichnung : " << bezeichnung << std::endl;
}
