
#ifndef SORPRESACASAHOTEL_H
#define SORPRESACASAHOTEL_H

#include "Sorpresa.h"

using namespace std;

namespace civitas
{
	class SorpresaCasaHotel : public Sorpresa
	{
		public:
			SorpresaCasaHotel(string texto, int valor, MazoSorpresa* mazo);
			void aplicarAJugador(int actual, vector<Jugador*> todos);

			inline virtual ~SorpresaCasaHotel() {}
	};

}


#endif