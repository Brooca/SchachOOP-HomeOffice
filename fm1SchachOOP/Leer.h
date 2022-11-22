#pragma once
using namespace std;
#include <string>
#include <vector>
#include "Feld.h"

class Feld;

#include "Figur.h"

class Leer :
    public Figur
{
public:
    Leer(string); 
    vector<Feld> erlaubteFelderBerechnen(string);
};

