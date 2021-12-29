#include "GestionInmobiliaria.h"


civitas::GestionInmobiliaria::GestionInmobiliaria(OperacionInmobiliaria gest, int ip)
{
	this->propiedad = ip;
	this->operacion = gest;
}
