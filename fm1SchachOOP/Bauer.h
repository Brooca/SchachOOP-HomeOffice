#pragma once
#include "Figur.h"
class Bauer :
    public Figur
{
public:
    Bauer(bool);
    std::vector<std::string> erlaubteFelderBerechnen(std::string);
};

