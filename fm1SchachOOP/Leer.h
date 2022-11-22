#pragma once
using namespace std;
#include <string>
#include <vector>
#include "FeldFigur.h"

class Feld;



class Leer :
    public Figur
{
public:
    Leer(string); 
    vector<Feld> erlaubteFelderBerechnen(string);
};

