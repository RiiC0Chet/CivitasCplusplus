#pragma once
#include <iostream>
#include <string>

namespace civitas
{
	enum OperacionJuego 
	{
		PASAR_TURNO,
		AVANZAR,
		COMPRAR,
		GESTIONAR
	};

    inline std::string toString(OperacionJuego c)
    {
        switch (c)
        {
        case PASAR_TURNO: return"PASAR_TURNO";    break;
        case AVANZAR: return"AVANZAR"; break;
        case COMPRAR: return "COMPRAR";  break;
        case GESTIONAR: return "GESTIONAR";   break;
        default: return"";;
        }
    }
}


