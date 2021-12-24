#pragma once
#include "Casilla.h"

using namespace std;

namespace civitas
{
	class CasillaCalle : public Casilla
	{
		private:
			float precioCompra, precioEdificar, precioBaseAlquiler;
			int numCasas, numHoteles;

			const static int FACTORALQUILERCALLE = 1, FACTORALQUILERCASA = 1, FACTORALQUILERHOTEL = 4;
			Jugador propietario;
		public:
			CasillaCalle(string n, int precio_Compra, int precio_Edificar, int precio_Base_alquiler);
	};

}

