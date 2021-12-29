#include "SorpresaConvertirme.h"

civitas::SorpresaConvertirme::SorpresaConvertirme(string texto, int valor, MazoSorpresa& mazo) : Sorpresa(texto, valor, mazo) {}

void civitas::SorpresaConvertirme::aplicarAJugador(int actual, vector<Jugador*> todos)
{
    //JugadorEspeculador *jugador =;
    informe(actual, todos);
    todos.at(actual) = todos.at(actual)->convertir();
}
