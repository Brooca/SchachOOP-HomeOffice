#include "Springer.h"

Springer::Springer(bool symbol)
{
	farbe = symbol;
	bezeichnung = (symbol) ? 'S' : 's';
}