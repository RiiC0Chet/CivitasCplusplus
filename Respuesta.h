#pragma once
#include <iostream>
#include <string>

namespace controladorCivitas
{
    enum Respuesta
    {
        SI,
        NO
    };

    inline std::string toString(Respuesta c)
    {
        switch (c)
        {
        case SI: return"SI";    break;
        case NO: return"NO"; break;
        default: return"";;
        }
    }
}