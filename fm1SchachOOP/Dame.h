#pragma once
using namespace std;
#include <vector>
#include <string>
#include "Feld.h"

class Feld;

#include "Laeufer.h"
#include "Turm.h"

class Dame: 
    public Figur
{
public:
  Dame(bool);
  vector<Feld> erlaubteFelderBerechnen(string);
};

