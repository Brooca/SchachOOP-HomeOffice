#pragma once
#include "Figur.h"

class Turm :
    public Figur
{
private:

public:
    Turm();
    Turm(bool);
    std::vector<std::string> erlaubteFelderBerechnen(std::string);
};

