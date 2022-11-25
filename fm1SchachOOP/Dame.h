#pragma once
#include "FeldFigur.h"



class Dame: 
    public Figur
{
public:
  Dame(bool);

  vector<Feld> erlaubteFelderBerechnen(string);
};

