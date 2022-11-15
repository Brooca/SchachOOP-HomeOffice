#pragma once
using namespace std;
#include <vector>
#include <string>

#include "Laeufer.h"
#include "Turm.h"

class Dame :
    public Laeufer, public Turm
{
public:
  Dame(bool);
  vector<string> erlaubteFelderBerechnen(string);
};

