#pragma once
#include <iostream>
#include <string>
namespace civitas
{
    enum OperacionInmobiliaria
    {
        CONSTRUIR_CASA,
        CONSTRUIR_HOTEL,
        TERMINAR
	};

    inline std::string toString(OperacionInmobiliaria c)
    {
        switch (c)
        {
        case CONSTRUIR_CASA: return"CONSTRUIR_CASA";    break;
        case CONSTRUIR_HOTEL: return"CONSTRUIR_HOTEL"; break;
        case TERMINAR: return "TERMINAR";  break;
        default: return"";;
        }
    }
    
}


