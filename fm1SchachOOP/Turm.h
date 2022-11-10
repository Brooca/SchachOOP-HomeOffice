#pragma once
#include "Figur.h"
class Turm :
    public Figur
{
public:
    Turm(bool);
    std::vector<std::string> erlaubteFelderBerechnen(std::string);
};

