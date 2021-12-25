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

void civitas::CasillaCalle::recibeJugador(int i_actual, vector<Jugador> todos)
{
    informe(i_actual, todos);
    Jugador aux = todos.at(i_actual);


    if (!this->tienePropietario()) {
        aux.puedeComprarCasilla();
    }
    else {
        tramitarAlquiler(aux);
    }
}
bool civitas::CasillaCalle::tienePropietario()
{
    if (propietario != nullptr)
        return true;
    else return false;
}
void civitas::CasillaCalle::tramitarAlquiler(Jugador& jugador)
{
    if (!esEsteElPropietario(jugador) && this->tienePropietario()) {

        float precio = this->getPrecioAlquilerCompleto();
        std::cout<<"El propietario de la propiedad es: " << this->propietario.getNombre() << " y " << jugador.getNombre() << " tiene que pagar: " << precio << " a no ser que sea especulador."<<endl;


        float nuevo_precio = jugador.paga(precio);
        this->propietario.modificarSaldo(nuevo_precio * (-1));

    }
}
bool civitas::CasillaCalle::igualdadEstado(CasillaCalle& otraCasilla)
{
    if (this == (&otraCasilla)) 
    {
        return true;
    }
    else 
    {


        if (this->getNombre().compare(otraCasilla.getNombre()) && precioCompra == otraCasilla.getPrecioCompra()
            && precioEdificar == otraCasilla.getPrecioEdificar() && this->getPrecioAlquilerCompleto() == otraCasilla.getPrecioAlquilerCompleto()
            && numCasas == otraCasilla.getNumCasas() && numHoteles == getNumHoteles()) 
        {
            return true;
        }

        else return false;
    }
}
string civitas::CasillaCalle::toString():Casilla() // Ta mal
{
    if (this->propietario == nullptr)
        return (". Precios: Compra: " + precioCompra + ", Edificar: " + precioEdificar + ", Alquiler base: " + precioBaseAlquiler + ", Alquiler Completo: " + getPrecioAlquilerCompleto() + ", Casas: " + numCasas + ", Hoteles: " + numHoteles);
    else return  (" con el propietario " + propietario.getNombre());

}
