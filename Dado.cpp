#include "Dado.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

civitas::Dado:: Dado(bool d) :debug(d), ultimoResultado(0)
{
	//this->instance = nullptr;
}

civitas::Dado* civitas::Dado::getInstance(bool d)
{
	//if (instance == nullptr)
		//instance = new Dado(d);
	static Dado instance(d);
	return &instance;
}


int civitas::Dado::tirar()
{
	// Iniciando el generador con una semilla 
	srand((unsigned)time(0));

	if (!debug)// Generando un número aleatorio en el rango [0,7)
		ultimoResultado = (rand() % 6)+1;
	else
		ultimoResultado = 1;
	return ultimoResultado;
}

int civitas::Dado::quienEmpieza(int n)
{
	// Iniciando el generador con una semilla 
	srand((unsigned)time(0));

	return (rand() % n);
}

void civitas::Dado::setDebug(bool d)
{
	debug = d;

	if (debug)
		Diario::getInstance()->ocurreEvento("Se ha establecido el modo debug del dado.");
}
