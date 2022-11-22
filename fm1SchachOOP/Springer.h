#pragma once
using namespace std;
#include <string>
#include <vector>
#include "Feld.h"

class Feld;

#include "Figur.h"

class Springer :
    public Figur
{
public:
    Springer(bool);
    vector<Feld> erlaubteFelderBerechnen(string);
};

