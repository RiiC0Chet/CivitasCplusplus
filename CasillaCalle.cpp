#include "CasillaCalle.h"

civitas::CasillaCalle::CasillaCalle(string n, int precio_Compra, int precio_Edificar, int precio_Base_alquiler):Casilla(n)
{
	this->propietario = nullptr;
    this->precioCompra = precio_Compra;
    this->precioEdificar = precio_Edificar;
    this->precioBaseAlquiler = precio_Base_alquiler;
    this->numCasas = 0;
    this->numHoteles = 0;
}

bool civitas::CasillaCalle::comprar(Jugador &jugador)
{
    (&propietario) = (&jugador);
    jugador.paga(getPrecioCompra());
    return true;
}

bool civitas::CasillaCalle::construirCasa(Jugador &jugador)
{
    jugador.paga(precioEdificar);
    numCasas++;
    return true;
}

bool civitas::CasillaCalle::construirHotel(Jugador &jugador)
{
    this->propietario.paga(precioEdificar);
    numHoteles++;
    return true;
}

bool civitas::CasillaCalle::derruirCasas(int numero, Jugador &jugador)
{
    if (this->esEsteElPropietario(jugador) && numCasas >= numero) 
    {
        numCasas = numCasas - numero;
        return true;
    }
    else return false;
}

bool civitas::CasillaCalle::esEsteElPropietario(Jugador &jugador)
{
    if ((&jugador) == (&propietario))
        return true;
    else return false;
}

void recibeJugador(int i_actual, vector<Jugador> todos);
bool tienePropietario();
void tramitarAlquiler(Jugador& jugador);
bool igualdadEstado(CasillaCalle &otraCasilla);
string toString();
