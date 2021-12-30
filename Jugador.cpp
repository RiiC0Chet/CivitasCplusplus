#include "Jugador.h"
#include "JugadorEspeculador.h"
#include "CasillaCalle.h"

using namespace civitas;

bool civitas::Jugador::existeLaPropiedad(int ip)
{
    if (propiedades.at(ip)->esEsteElPropietario(*this))
        return true;
    else 
        return false;
}

bool civitas::Jugador::puedoEdificarCasa(CasillaCalle &propiedad)
{
    if (this->puedoGastar(propiedad.getPrecioEdificar()) && propiedad.getNumCasas() < CASASPORHOTEL)
        return true;
    else 
        return false;
}

bool civitas::Jugador::puedoEdificarHotel(CasillaCalle &propiedad)
{
    if (this->puedoGastar(propiedad.getPrecioEdificar()) && propiedad.getNumHoteles() < HOTELESMAX && propiedad.getNumCasas() == CASASPORHOTEL)
        return true;
    else 
        return false;
}

civitas::Jugador::Jugador(Jugador& otro)
{
    this->nombre = otro.getNombre();
    this->casillaActual = otro.casillaActual;
    this->puedeComprar = otro.getPuedeComprar();

    this->saldo = otro.getSaldo();
    propiedades = otro.getPropiedades();
}

civitas::Jugador::Jugador(string nombre)
{
    this->nombre = nombre;
    this->casillaActual = 0;
    this->puedeComprar = false;

    this->saldo = SALDOINICIAL;
}

int civitas::Jugador::cantidadCasasHoteles()
{
    int total = 0;
    for (int i = 0; i < propiedades.size(); i++)
        total += propiedades.at(i)->getNumCasas() + propiedades.at(i)->getNumHoteles();

    return total;
}

int civitas::Jugador::compareTo(Jugador& otro)
{
    if (saldo == otro.getSaldo())
        return 0;
    else if (saldo < otro.getSaldo()) 
        return -1;
    else 
        return 1;
}

bool civitas::Jugador::comprar(CasillaCalle& titulo)
{
    bool result = false;

    if (this->puedeComprar) {

        float precio = titulo.getPrecioCompra();

        if (this->puedoGastar(precio)) 
        {
            result = titulo.comprar(*this);
            propiedades.push_back(&titulo);
            Diario::getInstance()->ocurreEvento("El jugador " + this->nombre + " compra la propiedad " + titulo.getNombre());
            this->puedeComprar = false;

        }

        else
            Diario::getInstance()->ocurreEvento("El jugador" + this->nombre + " no tiene saldo para comprar la propiedad " + titulo.getNombre() );

    }

    return result;
}

bool civitas::Jugador::construirCasa(int ip)
{
    bool result = false;
    bool existe = existeLaPropiedad(ip);

    if (existe) 
    {

        CasillaCalle *propiedad = propiedades.at(ip);
        bool puedoEdificar = puedoEdificarCasa(*propiedad);
        float precioEdificar = propiedad->getPrecioEdificar();


        if (puedoEdificar) 
        {
            result = propiedad->construirCasa(*this);
            Diario::getInstance()->ocurreEvento("El jugador " + nombre + " contruye casa en la propiedad " + to_string(ip) );
        }

    }


    Diario::getInstance()->ocurreEvento( propiedades.at(ip)->toString() + " tiene " + to_string(propiedades.at(ip)->getNumCasas())  + " casas y tiene " + to_string(propiedades.at(ip)->getNumHoteles()) + " hoteles. \n");
    return result;
}

bool civitas::Jugador::construirHotel(int ip)
{
    bool result = false;

    if (existeLaPropiedad(ip)) 
    {
        CasillaCalle *propiedad = propiedades.at(ip);
        bool puedoEdificarhotel = puedoEdificarHotel(*propiedad);

        float precio = propiedad->getPrecioEdificar();

        if (puedoEdificarhotel) 
        {
            result = propiedad->construirHotel(*this);
            propiedad->derruirCasas(CASASPORHOTEL, *this);
            Diario::getInstance()->ocurreEvento("El jugador " + nombre + " construye hotel en la propiedad " + to_string(ip) );
        }

    }

    Diario::getInstance()->ocurreEvento(propiedades.at(ip)->toString() + " tiene " + to_string(propiedades.at(ip)->getNumCasas()) + " casas y tiene " + to_string(propiedades.at(ip)->getNumHoteles()) + " hoteles. \n");
    return result;
}

bool civitas::Jugador::enBancarrota()
{
    if (saldo < 0)
        return true;
    else 
        return false;
}

float civitas::Jugador::modificarSaldo(float cantidad)
{
    this->saldo += cantidad;
    Diario::getInstance()->ocurreEvento("El jugador " + nombre + " se le modifica el saldo en " + to_string(cantidad) );
    return cantidad;
}

bool civitas::Jugador::moverACasilla(int num_Casilla)
{
    casillaActual = num_Casilla;
    puedeComprar = false;
    Diario::getInstance()->ocurreEvento("El jugador " + nombre + " ha caido en la casilla numero: " + to_string(num_Casilla) );
    return true;
}

float civitas::Jugador::paga(float cantidad)
{
    return modificarSaldo(cantidad * (-1));
}

float civitas::Jugador::pagaAlquiler(float cantidad)
{
    return paga(cantidad);
}

bool civitas::Jugador::pasaPorSalida()
{
    recibe(PASOPORSALIDA);

    Diario::getInstance()->ocurreEvento("El jugador " + nombre + " ha pasado por la salida.");
    Diario::getInstance()->leerEvento();

    Diario::getInstance()->ocurreEvento("--> El jugador " + nombre + " ha pasado por la salida.");
    return true;
}

bool civitas::Jugador::puedeComprarCasilla()
{
    puedeComprar = true;
    return puedeComprar;
}

bool civitas::Jugador::puedoGastar(float precio)
{
    if (getSaldo() >= precio)
        return true;
    else 
        return false;
}

float civitas::Jugador::recibe(float cantidad)
{
    return modificarSaldo(cantidad);
}

bool civitas::Jugador::tieneAlgoQueGestionar()
{
    if (propiedades.size() >= 1)
        return true;
    else 
        return false;
}

civitas::Jugador* civitas::Jugador::convertir()
{
    Diario::getInstance()->ocurreEvento("El jugador " + nombre + " se ha convertido en especulador.");

    return new JugadorEspeculador(*this);
}


civitas::Jugador::~Jugador()
{
    for (int i = 0; i < propiedades.size(); ++i)
        delete[] propiedades.at(i);
}