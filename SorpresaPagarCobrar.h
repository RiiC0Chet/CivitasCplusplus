
#ifndef SORPRESAPAGARCOBRAR_H
#define SORPRESAPAGARCOBRAR_H

#include "Sorpresa.h"

using namespace std;

namespace civitas
{
	class SorpresaPagarCobrar : public Sorpresa
	{
	public:
		SorpresaPagarCobrar(string texto, int valor, MazoSorpresa* mazo);
		void aplicarAJugador(int actual, vector<Jugador*> todos);
		inline virtual ~SorpresaPagarCobrar() {}
	};

}


#endif