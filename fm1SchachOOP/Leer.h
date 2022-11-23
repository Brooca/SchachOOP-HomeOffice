#pragma once
#include "FeldFigur.h"

class Leer :
    public Figur
{
public:
    Leer(string); 
    vector<Feld> erlaubteFelderBerechnen(string);
};