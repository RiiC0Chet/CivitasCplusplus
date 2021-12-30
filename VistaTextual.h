
#ifndef VISTATEXTUAL_H
#define VISTATEXTUAL_H

#include "CivitasJuego.h"
#include "Respuesta.h"
#include "Vista.h"
#include <iostream>
using namespace std;

namespace vistaTextualCivitas
{
	class VistaTextual : public Vista
	{
		private:
			string separador;
			string basura; // recogemos la basura que se introduce por teclado
			CivitasJuego *juegoModel;
		public:
			VistaTextual(CivitasJuego &juegoModel);
			void pausa()override;
			int leeEntero(int max, string msg1, string msg2);
			int menu(string titulo, vector<string> lista);
			void actualiza()override;
			controladorCivitas::Respuesta comprar()override;
			OperacionInmobiliaria elegirOperacion()override;
			int elegirPropiedad()override;

			inline void mostrarSiguienteOperacion(OperacionJuego operacion) 
			{
				cout << ("\n--> Ha decidido: " + toString(operacion) + "\n");
			}

			void mostrarEventos()override;
			void mostrarEstado();

			~VistaTextual();
	};

}

#endif