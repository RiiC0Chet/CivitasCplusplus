#include "Dado.h"

civitas::Dado:: Dado(bool d) :debug(d), ultimoResultado(0)
{
	this->instance = nullptr;
}

const civitas::Dado* civitas::Dado::getInstance(bool d)
{
	if (instance == nullptr)
		instance = new Dado(d);

	return instance;
}
