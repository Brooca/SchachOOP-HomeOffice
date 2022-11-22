#pragma once
using namespace std;
#include <string>
#include <vector>
#include "Feld.h"

class Feld;

#include "Figur.h"

class Laeufer :
    public Figur
{
public:
    Laeufer();
    Laeufer(bool);
    vector<Feld> erlaubteFelderBerechnen(string);
};