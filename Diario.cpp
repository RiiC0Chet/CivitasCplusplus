#include "Diario.h"
civitas::Diario* civitas::Diario::getInstance()
{
	static Diario instance;// = new Diario();
	return &instance;
}
string civitas::Diario::leerEvento()
{
	string salida = "";
	if (!eventos.empty())
	{
		salida = eventos.at(0);
		eventos.erase(eventos.begin());// Elimina el primer elemento 
									   //y moviliza los de detras a alante
	}
		
	
	return salida;
}
