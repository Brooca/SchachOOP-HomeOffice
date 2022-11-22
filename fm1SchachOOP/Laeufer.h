#pragma once
using namespace std;
#include <string>
#include <vector>
#include "FeldFigur.h"

class Feld;



class Laeufer :
    public Figur
{
public:
    Laeufer();
    Laeufer(bool);
    vector<Feld> erlaubteFelderBerechnen(string);
};