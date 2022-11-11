#pragma once

#include "Laeufer.h"
#include "Turm.h"

class Dame :
    public Laeufer, public Turm
{
private:
    bool farbe;
    char bezeichnung;
public:
    Dame(bool);
    std::vector<std::string> erlaubteFelderBerechnen(std::string);
};

