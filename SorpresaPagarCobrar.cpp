#include "SorpresaPagarCobrar.h"


civitas::SorpresaPagarCobrar::SorpresaPagarCobrar(string texto, int valor, MazoSorpresa* mazo) : Sorpresa(texto,valor,mazo) {}

void civitas::SorpresaPagarCobrar::aplicarAJugador(int actual, vector<Jugador*> todos)
{
    Diario::getInstance()->ocurreEvento("\n El jugador ha caido en una casilla sorpresa del tipo: PagarCobrar");
    Diario::getInstance()->ocurreEvento("--> " + toString() + "\n");
    informe(actual, todos);

    if (valor < 0)
        todos.at(actual)->paga(valor);
    else
        todos.at(actual)->modificarSaldo(valor);

}
