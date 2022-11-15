#pragma once
using namespace std;
#include <vector>
#include <string>

#include "Figur.h"

class Bauer :
    public Figur
{
public:
    Bauer(bool);
    vector<string> erlaubteFelderBerechnen(string);
};

