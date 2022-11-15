#pragma once
using namespace std;
#include <string>
#include <vector>

#include "Figur.h"

class Springer :
    public Figur
{
public:
    Springer(bool);
    vector<string> erlaubteFelderBerechnen(string);
};

