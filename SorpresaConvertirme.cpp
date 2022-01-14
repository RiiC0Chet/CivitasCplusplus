#include "SorpresaConvertirme.h"

civitas::SorpresaConvertirme::SorpresaConvertirme(string texto, int valor, MazoSorpresa* mazo) : Sorpresa(texto, valor, mazo) {}

void civitas::SorpresaConvertirme::aplicarAJugador(int actual, vector<Jugador*> todos)
{
    informe(actual, todos);

    Jugador* aux = todos.at(actual);

    todos.at(actual) = todos.at(actual)->convertir();
}
