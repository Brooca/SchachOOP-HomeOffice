#pragma once
#include "Figur.h"
#include <string>
class Leer :
    public Figur
{
public:
    Leer(std::string); 
    std::vector<std::string> erlaubteFelderBerechnen(std::string);
};

