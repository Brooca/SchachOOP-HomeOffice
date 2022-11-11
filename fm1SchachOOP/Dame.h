#pragma once
#include "Figur.h"
class Dame :
    public Figur
{
public:
    Dame(bool);
    std::vector<std::string> erlaubteFelderBerechnen(std::string);
};

