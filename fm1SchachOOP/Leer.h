#pragma once
using namespace std;
#include <string>
#include <vector>

#include "Figur.h"

class Leer :
    public Figur
{
public:
    Leer(string); 
    vector<string> erlaubteFelderBerechnen(string);
};

