#include "modello.h"

Modello::Modello(string p):path(p){}

Modello::~Modello()
{
    if(q) delete[]q;
}

