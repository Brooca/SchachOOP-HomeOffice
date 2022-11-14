#pragma once
#include "Figur.h"
#include <string>
#include <vector>

class Springer :
    public Figur
{
public:
    Springer(bool);
   std::vector<std::string> erlaubteFelderBerechnen(std::string);
};

