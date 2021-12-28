#include "MazoSorpresa.h"
#include <algorithm>

void civitas::MazoSorpresa::init()
{
    if (!sorpresas.empty())
        sorpresas.clear();

    barajada = false;
    usadas = 0;
    debug = false;
}

civitas::MazoSorpresa::MazoSorpresa(bool d)
{
    init();
    debug = d;

    if (debug)
       Diario::getInstance()->ocurreEvento("Se ha establecido el modo debug del MazoSorpresa.");
}

civitas::MazoSorpresa::MazoSorpresa()
{
    init();
    debug = false;
}

void civitas::MazoSorpresa::alMazo(Sorpresa& s)
{
    if (!barajada)
        sorpresas.push_back(&s);
        
}

civitas::Sorpresa* civitas::MazoSorpresa::siguiente()
{
    if (!barajada || usadas == sorpresas.size())
    {
        if (!debug)
        {
            random_shuffle(sorpresas.begin(), sorpresas.end());// barajamos el vector
            usadas = 0;
            barajada = true;
        }
        usadas = 0;
    }

    Sorpresa *auxiliar = sorpresas.at(usadas);
    usadas++;


    return auxiliar;
}

