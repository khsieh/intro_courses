#include <iostream>
#include "tune.h"

using namespace std;

Tune::Tune()
:title("")
{}

Tune::Tune(string n)
:title(n)
{}

string Tune::get_title()
{
    return this -> title;
}
