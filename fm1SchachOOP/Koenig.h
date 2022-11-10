#pragma once
#include "Figur.h"
class Koenig :
    public Figur
{ 
public:
    Koenig(bool);
    std::vector<std::string> erlaubteFelderBerechnen();
};

