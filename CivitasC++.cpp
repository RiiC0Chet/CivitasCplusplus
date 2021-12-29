// CivitasC++.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "CivitasJuego.h"
#include <vector>
#include "SorpresaConvertirme.h"

using namespace std;
using namespace civitas;

int main()
{
    std::cout << "Hello World!\n";

    vector<string> nombres;
    nombres.push_back("Vilma");
    nombres.push_back("Pedro");

    CivitasJuego *juego = new CivitasJuego(nombres, true);
    Diario *diario = Diario::getInstance();

    diario->ocurreEvento(juego->getJugadores().at(0)->toString());
    diario->ocurreEvento(juego->getJugadores().at(1)->toString());

    diario->ocurreEvento("\n ------------------------------ \n");

    diario->ocurreEvento("Turno de " + juego->getJugadorActual()->getNombre());

    juego->getJugadorActual()->moverACasilla(1);
    juego->getJugadorActual()->puedeComprarCasilla();
    diario->ocurreEvento(juego->getTablero()->getCasilla(1)->toString());

    diario->ocurreEvento("\n ------------------------------ \n");

    juego->getJugadorActual()->comprar(*((CasillaCalle*)juego->getTablero()->getCasilla(1)));


    diario->ocurreEvento("\n ------------------------------ \n");

    diario->ocurreEvento(juego->getJugadores().at(0)->toString());
    diario->ocurreEvento(juego->getJugadores().at(1)->toString());

    diario->ocurreEvento("\n ------------------------------ \n");
    
    SorpresaConvertirme *sorpresa = new SorpresaConvertirme("Convertir Jugador a especulador", 0, nullptr);
    sorpresa->aplicarAJugador(juego->getIndiceJugadorActual(), juego->getJugadores());

    diario->ocurreEvento(juego->getJugadorActual()->toString());
    diario->ocurreEvento(juego->getTablero()->getCasilla(1)->toString());


    diario->ocurreEvento("\n ------------------------------ \n");

    juego->getJugadorActual()->moverACasilla(2);
    juego->getJugadorActual()->puedeComprarCasilla();
    diario->ocurreEvento(juego->getTablero()->getCasilla(2)->toString());

    diario->ocurreEvento("\n ------------------------------ \n");

    juego->getJugadorActual()->comprar(*((CasillaCalle*)juego->getTablero()->getCasilla(1)));


    diario->ocurreEvento("\n ------------------------------ \n");

    diario->ocurreEvento(juego->getJugadores().at(0)->toString());
    diario->ocurreEvento(juego->getJugadores().at(1)->toString());

    diario->ocurreEvento("\n ------------------------------ \n");

    juego->getJugadorActual()->convertir();

    diario->ocurreEvento("\n ------------------------------ \n");

    while (diario->eventosPendientes()) {
        cout << diario->leerEvento() << endl ;
    }
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
