#pragma once

#include "OperacionInmobiliaria.h"
#include "OperacionJuego.h"
//#include "Respuesta.h"

using namespace civitas;

namespace vistaTextualCivitas
{
	class Vista
	{
		public:
            virtual void actualiza() = 0;

            virtual void pausa() = 0;

            virtual controladorCivitas::Respuesta comprar() = 0;

            virtual OperacionInmobiliaria elegirOperacion() = 0;

            virtual int elegirPropiedad() = 0;

            virtual void mostrarSiguienteOperacion(OperacionJuego operación) = 0;

            virtual void mostrarEventos() = 0;
	};

}
