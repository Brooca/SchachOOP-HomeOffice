#pragma once
using namespace std;
#include <vector>
#include <string>
#include "FeldFigur.h"

class Feld;


class Bauer :
    public Figur
{
public:
    Bauer(bool);
    vector<Feld> erlaubteFelderBerechnen(string);
};

