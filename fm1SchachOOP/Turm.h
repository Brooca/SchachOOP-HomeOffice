#pragma once
using namespace std;
#include <vector>
#include <string>
#include "Feld.h"

class Feld;

#include "Figur.h"

class Turm :
    public Figur
{
private:

public:
    Turm();
    Turm(bool);
    vector<Feld> erlaubteFelderBerechnen(string);
};

