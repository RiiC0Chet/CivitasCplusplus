#include "Casilla.h"


bool civitas::Casilla::igualdadIdentidad(Casilla &otraCasilla)
{
    if (this == &otraCasilla)
        return true;
    else
        return false;
}

bool civitas::Casilla::igualdadEstado(Casilla &otraCasilla)
{
    if ( this == &otraCasilla) 
        return true;
    else 
    {

        if (nombre.compare(otraCasilla.getNombre())) 
        {

            return true;
        }

        else return false;
    }

}
