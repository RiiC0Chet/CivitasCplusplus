#pragma once
#include "iostream"
#include "Casilla.h"

using namespace std;

namespace civitas
{
	class CasillaSorpresa : public Casilla
	{
		private:
			Sorpresa sorpresa;
			MazoSorpresa mazo;
		public:
			CasillaSorpresa(string nombre, MazoSorpresa &mazo);
			void recibeJugador(int i_actual, vector<Jugador*> todos);
			bool igualdadEstado(CasillaSorpresa &otraCasilla);
			inline string toString() 
			{
				return Casilla::toString() + " de tipo sorpresa";
			}
	};
}

