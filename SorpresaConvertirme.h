
#ifndef SORPRESACONVERTIRME_H
#define SORPRESACONVERTIRME_H

#include "Sorpresa.h"

using namespace std;

namespace civitas
{
	class SorpresaConvertirme : public Sorpresa
	{
	public:
		SorpresaConvertirme(string texto, int valor, MazoSorpresa* mazo);
		void aplicarAJugador(int actual, vector<Jugador*> todos);
	};

}


#endif