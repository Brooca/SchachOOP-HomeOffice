#pragma once
using namespace std;
#include <vector>
#include <string>
#include "FeldFigur.h"

class Feld;


class Turm :
    public Figur
{
private:

public:
    Turm();
    Turm(bool);
    vector<Feld> erlaubteFelderBerechnen(string);
};

