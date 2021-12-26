#include "CasillaSorpresa.h"

civitas::CasillaSorpresa::CasillaSorpresa(string nombre, MazoSorpresa &mazo):Casilla(nombre)
{
	this->sorpresa = nullptr;
	this->mazo = mazo;
}

void civitas::CasillaSorpresa::recibeJugador(int i_actual, vector<Jugador> todos)
{
	sorpresa = mazo.siguiente();
	informe(i_actual, todos);
	sorpresa.aplicarAJugador(i_actual, todos);
}

bool civitas::CasillaSorpresa::igualdadEstado(CasillaSorpresa &otraCasilla)
{
    if (this == (&otraCasilla) ) 
        return true;
    else 
    {
        if ( &sorpresa == &otraCasilla.sorpresa && &mazo == &otraCasilla.mazo) 
            return true;
        else 
            return false;
    }
}

