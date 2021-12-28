//#pragma once
#include <string>
#include <vector>
//#include "Diario.h"
//#include "Jugador.h"


#ifndef CASILLA_H
#ifdef CASILLA_H 
using namespace std;

namespace civitas
{
	class Casilla
	{
	private:
		string nombre;

	public:
		inline Casilla(string n)
		{
			this->nombre = n;
		}

		inline string getNombre()
		{
			return nombre;
		}

		inline void informe(int i_actual, vector<Jugador*> todos) 
		{
			Diario::getInstance()->ocurreEvento("El jugador " + todos.at(i_actual)->getNombre() + " ha caido en la casilla: " + this->toString());
		}

		inline void recibeJugador(int i_actual, vector<Jugador*> todos)
		{
			informe(i_actual, todos);
		}

		bool igualdadIdentidad(Casilla &otraCasilla);

		bool igualdadEstado(Casilla &otraCasilla);

		inline string toString() 
		{
			return "Casilla: " + nombre;
		}
	};


}

#endif
