#pragma once
using namespace std;
#include <vector>
#include <string>
#include "Feld.h"

class Feld;

#include "Figur.h"

class Bauer :
    public Figur
{
public:
    Bauer(bool);
    vector<Feld> erlaubteFelderBerechnen(string);
};

