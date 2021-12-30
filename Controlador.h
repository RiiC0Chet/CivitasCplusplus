
#ifndef CONTROLADOR_h
#define CONTROLADOR_H

#include "CivitasJuego.h"
#include "VistaTextual.h"

using namespace std;
using namespace civitas;
using namespace vistaTextualCivitas;

namespace controladorCivitas
{
	class Controlador
	{
		private:
			CivitasJuego *juego;
			VistaTextual *vista;
		public:
			Controlador(CivitasJuego &juego, VistaTextual &vista);
			void juega();

			~Controlador();

	};
}




#endif