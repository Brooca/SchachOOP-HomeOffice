#pragma once
#include "FeldFigur.h"

class Springer :
    public Figur
{
public:
    Springer(bool);
    vector<Feld> erlaubteFelderBerechnen(string);
};

