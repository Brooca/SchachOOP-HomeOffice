#pragma once
#include "FeldFigur.h"

class Turm :
    public Figur
{
public:
    Turm(bool);
    vector<Feld> erlaubteFelderBerechnen(string);
};

