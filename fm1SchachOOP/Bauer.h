#pragma once
#include "FeldFigur.h"

class Bauer :
    public Figur
{
public:
    Bauer(bool);
    vector<Feld> erlaubteFelderBerechnen(string);
};

