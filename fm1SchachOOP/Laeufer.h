#pragma once
using namespace std;
#include <string>
#include <vector>

#include "Figur.h"

class Laeufer :
    public Figur
{
public:
    Laeufer();
    Laeufer(bool);
    vector<string> erlaubteFelderBerechnen(string);
};