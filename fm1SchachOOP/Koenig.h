#pragma once
using namespace std;
#include <vector>
#include <string>
#include "Feld.h"

class Feld;

#include "Figur.h"

class Koenig :
    public Figur
{ 
public:
    Koenig(bool);
    vector<Feld> erlaubteFelderBerechnen(string);
};

