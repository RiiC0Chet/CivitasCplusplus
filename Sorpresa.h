//#pragma once
#include <string>
//#include "Jugador.h"

#ifndef SORPRESA_H
#define SORPRESA_H
namespace civitas
{
	class Sorpresa
	{
		private:
		protected:
			string texto;
			int valor;
			MazoSorpresa mazo;

			inline void informe(int actual, vector<Jugador*> todos)
			{
				Diario::getInstance()->ocurreEvento("El jugador " + todos.at(actual)->getNombre() + " se le esta aplicando una sorpresa: " + texto);
			}

		public:
			Sorpresa(string texto, int valor, MazoSorpresa &mazo);
			virtual void  aplicarAJugador(int actual, vector<Jugador*> todos)=0;

			inline string toString()
			{
				return texto;
			}
	};

}

#endif