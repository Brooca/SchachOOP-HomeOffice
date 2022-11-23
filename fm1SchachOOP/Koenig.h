#pragma once
#include "FeldFigur.h"

class Koenig :
    public Figur
{ 
public:
    Koenig(bool);
    vector<Feld> erlaubteFelderBerechnen(string);
};

