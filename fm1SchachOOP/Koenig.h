#pragma once
using namespace std;
#include <vector>
#include <string>
#include "FeldFigur.h"

class Feld;



class Koenig :
    public Figur
{ 
public:
    Koenig(bool);
    vector<Feld> erlaubteFelderBerechnen(string);
};

