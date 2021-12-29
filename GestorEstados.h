
#ifndef GESTORESTADOS_H
#define GESTORESTADOS_H

#include "EstadoJuego.h"
#include "Jugador.h"
#include "OperacionJuego.h"
#include "Diario.h"

namespace civitas
{
	class GestorEstados
	{
		public:
			inline EstadoJuego estadoInicial() 
			{
				return (EstadoJuego::INICIO_TURNO);
			}
			OperacionJuego siguienteOperacion(Jugador& jugador, EstadoJuego estado);
			EstadoJuego siguienteEstado(Jugador &jugador, EstadoJuego estado, OperacionJuego operacion);
	};
}


#endif