#pragma once
using namespace std;
#include <vector>
#include <string>

#include "Figur.h"

class Koenig :
    public Figur
{ 
public:
    Koenig(bool);
    vector<string> erlaubteFelderBerechnen(string);
};

