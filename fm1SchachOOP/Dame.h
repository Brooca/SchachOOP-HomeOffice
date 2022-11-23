#pragma once
#include "FeldFigur.h"

#include "Laeufer.h"
#include "Turm.h"

class Dame: 
    public Figur
{
public:
  Dame(bool);
  vector<Feld> erlaubteFelderBerechnen(string);
};

