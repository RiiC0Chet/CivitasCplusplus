#pragma once
#include <iostream>
#include <string>

namespace civitas
{
	enum EstadoJuego
	{
		INICIO_TURNO,
		DESPUES_AVANZAR,
		DESPUES_COMPRAR,
		DESPUES_GESTIONAR
	};

    inline std::string toString(EstadoJuego c)
    {
        switch (c)
        {
        case INICIO_TURNO: return"INICIO_TURNO";    break;
        case DESPUES_AVANZAR: return"DESPUES_AVANZAR"; break;
        case DESPUES_COMPRAR: return "DESPUES_COMPRAR";  break;
        case DESPUES_GESTIONAR: return "DESPUES_GESTIONAR";   break;
        default: return"";;
        }
    }
}


