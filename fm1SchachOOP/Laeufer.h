#pragma once
#include "FeldFigur.h"

class Laeufer :
    public Figur
{
public:
    Laeufer(bool);
    vector<Feld> erlaubteFelderBerechnen(string);
};