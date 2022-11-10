#pragma once
#include "Figur.h"
#include <string>
#include <vector>

class Springer :
    public Figur
{
public:
    Springer(bool);
    // erlaubte Felder berechnen()
   std::vector<std::string> erlaubteFelderBerechnen(std::string);
};

