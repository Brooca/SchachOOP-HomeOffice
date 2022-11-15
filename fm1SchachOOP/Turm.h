#pragma once
using namespace std;
#include <vector>
#include <string>

#include "Figur.h"

class Turm :
    public Figur
{
public:
    Turm();
    Turm(bool);
    vector<string> erlaubteFelderBerechnen(string);
};

