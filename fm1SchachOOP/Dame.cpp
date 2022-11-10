#include "Dame.h"

Dame::Dame(bool symbol)
{
	farbe = symbol;
	bezeichnung = (symbol) ? 'D' : 'd';
}
