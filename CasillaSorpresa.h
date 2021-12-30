
#ifndef CASILLASORPRESA_H
#define CASILLASORPRESA_H 

#include <iostream>
#include "Casilla.h"
#include "sorpresa.h"
#include "MazoSorpresa.h"

//class Sorpresa;
//class MazoSorpresa;


using namespace std;

namespace civitas
{
	class CasillaSorpresa : public Casilla
	{
		private:
			Sorpresa *sorpresa;
			MazoSorpresa *mazo;
		public:
			CasillaSorpresa(string nombre, MazoSorpresa &mazo);
			void recibeJugador(int i_actual, vector<Jugador*> todos);
			bool igualdadEstado(CasillaSorpresa &otraCasilla);
			inline string toString() 
			{
				return Casilla::toString() + " de tipo sorpresa";
			}

			virtual ~CasillaSorpresa();
	};
}

#endif