#pragma once
using namespace std;
#include <string>
#include <vector>
#include "FeldFigur.h"

class Feld;



class Springer :
    public Figur
{
public:
    Springer(bool);
    vector<Feld> erlaubteFelderBerechnen(string);
};

