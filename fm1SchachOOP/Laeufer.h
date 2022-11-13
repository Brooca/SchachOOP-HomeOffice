#pragma once
#include "Figur.h"

class Laeufer :
    public Figur
{
public:
    Laeufer();
    Laeufer(bool);
    std::vector<std::string> erlaubteFelderBerechnen(std::string);
};

