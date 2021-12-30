
#ifndef CIVITASJUEGO_H
#define CIVITASJUEGO_H

#include "Tablero.h"
#include "dado.h"
#include "GestorEstados.h"
#include "MazoSorpresa.h"

namespace civitas
{
	class CivitasJuego
	{
		private:
			 int indiceJugadorActual;

			 Tablero *tablero;
			 MazoSorpresa *mazo;
			 GestorEstados *gs;
			 EstadoJuego estado;

			 vector<Jugador*> jugadores;

			 Dado *dado;

			 void InicializaMazoSorpresas();
			 void inicializaTablero(MazoSorpresa &mazo);
		public:
			CivitasJuego(vector<string> nombres, bool debug);

			inline bool construirCasa(int ip)
			{
				return  jugadores.at(indiceJugadorActual)->construirCasa(ip);
			}

			inline bool construirHotel(int ip)
			{
				return  jugadores.at(indiceJugadorActual)->construirHotel(ip);
			}

			void contabilizarPasosPorSalida(Jugador &JugadorActual);
			bool finalDelJuego();

			inline int getIndiceJugadorActual()
			{
				return this->indiceJugadorActual;
			}

			inline Jugador* getJugadorActual()
			{
				return jugadores.at(indiceJugadorActual);
			}
			inline vector<Jugador*> getJugadores()
			{
				return jugadores;
			}

			inline Tablero* getTablero()
			{
				return tablero;
			}
			void pasarTurno();
			//bool comparar(Jugador& uno, Jugador& otro);
			vector<Jugador*> ranking();

			inline vector<Jugador*> _ranking()
			{
				return ranking();
			}

			inline void siguientePasoCompletado(OperacionJuego operacion)
			{
				estado = gs->siguienteEstado(*jugadores.at(indiceJugadorActual), estado, operacion);
			}

			void avanzaJugador();
			OperacionJuego siguientePaso();
			bool comprar();

			~CivitasJuego();
	};

}

#endif