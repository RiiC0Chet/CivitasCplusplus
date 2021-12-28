#include "JugadorEspeculador.h"

void civitas::JugadorEspeculador::actualizaPropiedadesPorConversion(Jugador& jugador)
{
	for (int i = 0; i < this->getPropiedades().size(); i++)
		this->getPropiedades().at(i)->actualizaPropietarioPorConversion(jugador);
}

bool civitas::JugadorEspeculador::comprar(CasillaCalle& titulo)
{
    bool result = false;

    if (getPuedeComprar()) {

        float precio = titulo.getPrecioCompra();

        if (Jugador::puedoGastar(precio)) {

            result = titulo.comprar(*this);
            this->getPropiedades().push_back(&titulo);
            Diario::getInstance()->ocurreEvento("El jugador " + getNombre() + ", jugador especulador compra la propiedad " + titulo.getNombre() );
            Jugador::puedeComprar = false;

        }

        else {

            Diario::getInstance()->ocurreEvento("El jugador" + getNombre() + ", jugador especulador no tiene saldo para comprar la propiedad " + titulo.getNombre());
        }

    }

    return result;
}
