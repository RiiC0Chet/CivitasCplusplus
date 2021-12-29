

#ifndef CASILLACALLE_H
#define CASILLACALLE_H 

#include <iostream>
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
			Jugador *propietario;
		public:
			CasillaCalle(string n, float precio_Compra, float precio_Edificar, float precio_Base_alquiler);
			bool comprar(Jugador &jugador);
			bool construirCasa(Jugador &jugador);
			bool construirHotel(Jugador &jugador);
			bool derruirCasas(int numero, Jugador &jugador);
			bool esEsteElPropietario(Jugador &jugador);

			inline int cantidadCasasHoteles()
			{
				return (numCasas + numHoteles);
			}
			
			inline float getPrecioCompra()
			{
				return precioCompra;
			}

			inline float getPrecioEdificar() 
			{
				return precioEdificar;
			}

			inline int getNumCasas() 
			{
				return numCasas;
			}

			inline int getNumHoteles() 
			{
				return numHoteles;
			}

			inline float getPrecioAlquilerCompleto() 
			{
				return (precioBaseAlquiler * (FACTORALQUILERCASA + numCasas + numHoteles * FACTORALQUILERHOTEL));
			}

			void recibeJugador(int i_actual, vector<Jugador*> todos);
			bool tienePropietario();
			void tramitarAlquiler(Jugador &jugador);
			bool igualdadEstado(CasillaCalle &otraCasilla);

			inline void actualizaPropietarioPorConversion(Jugador &nuevo)
			{
				propietario = &nuevo;
			}

			string toString();
	};

}

#endif

//#inluce "CasillaCalle_inline.h"
