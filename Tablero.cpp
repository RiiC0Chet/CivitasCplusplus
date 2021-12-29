#include "Tablero.h"

using namespace civitas;

civitas::Tablero::Tablero()
{
    porSalida = false;

    Casilla *salida = new Casilla("Salida");

    tablero.push_back(salida);
}

bool civitas::Tablero::computarPasoPorSalida()
{
    bool aux = porSalida;
    porSalida = false;

    return aux;
}

Casilla* civitas::Tablero::getCasilla(int numCasilla)
{
    if (tablero.at(numCasilla) != nullptr)
        return tablero.at(numCasilla);
    else 
        return nullptr;
}


int civitas::Tablero::nuevaPosicion(int actual, int tirada)
{
    int nueva_pos;

    if ((actual + tirada) >= tablero.size()) {

        porSalida = true;
        nueva_pos = (actual + tirada) % tablero.size();
        return nueva_pos;
    }

    else {
        nueva_pos = actual + tirada;
        return nueva_pos;
    }
}

bool civitas::Tablero::correcto(int numCasilla)
{
    if (numCasilla > 0 && numCasilla <= tablero.size())
        return true;
    else 
        return false;
}

