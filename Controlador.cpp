#include "Controlador.h"

controladorCivitas::Controlador::Controlador(CivitasJuego& juego, VistaTextual& vista)
{
	this->juego = &juego;
	this->vista = &vista;
}

void controladorCivitas::Controlador::juega()
{
    bool fin_juego = juego->finalDelJuego();
    while (!fin_juego)
    {
        vista->mostrarEstado();
        vista->actualiza();
        vista->pausa();

        civitas::OperacionJuego siguiente = juego->siguientePaso();
        vista->mostrarSiguienteOperacion(siguiente);

        if (siguiente != civitas::OperacionJuego::PASAR_TURNO)
            vista->mostrarEventos();

        fin_juego = juego->finalDelJuego();

        if (!fin_juego)
        {
            switch (siguiente)
            {
            case COMPRAR:

                if (vista->comprar() == Respuesta::SI)
                    juego->comprar();

                juego->siguientePasoCompletado(siguiente);

                break;

            case GESTIONAR:

                civitas::OperacionInmobiliaria operacion = vista->elegirOperacion();
                if (operacion != civitas::OperacionInmobiliaria::TERMINAR)
                {
                    int propiedad = vista->elegirPropiedad();

                    //civitas::GestionInmobiliaria gestion = civitas::GestionInmobiliaria(operacion, propiedad); ta mal pero se podria arreglar si hiciera falta (pd no lo hace)

                    if (operacion == civitas::OperacionInmobiliaria::CONSTRUIR_CASA)
                    {
                        juego->construirCasa(propiedad);
                    }
                    else
                    {
                        juego->construirHotel(propiedad);
                    }

                }
                else
                {
                    juego->siguientePasoCompletado(siguiente);
                }


                break;

            }


        }
        else
        {
            vista->actualiza();
        }

    }

    //vista.mostrarEstado();
}

controladorCivitas::Controlador::~Controlador()
{
    delete[] juego;
    delete[] vista;
}
