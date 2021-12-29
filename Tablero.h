
#ifndef TABLERO_H
#define TABLERO_H

#include "Casilla.h"
using namespace std;

namespace civitas
{
	class Tablero
	{
		private:
			vector<Casilla*> tablero;
			bool porSalida;

			bool correcto(int numCasilla);
		public:
			Tablero();
			bool computarPasoPorSalida();

			inline void añadeCasilla(Casilla* casilla)
			{
				tablero.push_back(casilla);
			}
			Casilla* getCasilla(int numCasilla);

			inline vector<Casilla*> getTodasCasillas()
			{
				return tablero;
			}

			int nuevaPosicion(int actual, int tirada);
	};
}


#endif