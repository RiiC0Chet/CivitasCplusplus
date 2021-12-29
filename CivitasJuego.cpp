#include "CivitasJuego.h"
#include "SorpresaConvertirme.h"
#include "SorpresaPagarCobrar.h"
#include "SorpresaCasaHotel.h"
#include "CasillaSorpresa.h"
#include "CasillaCalle.h"
#include <algorithm>

using namespace civitas;
using namespace std;

civitas::CivitasJuego::CivitasJuego(vector<string> nombres, bool debug)
{
    for (int i = 0; i < nombres.size(); i++)
    {
        Jugador *aux = new Jugador(nombres.at(i));
        jugadores.push_back(aux);
    }

    estado = gs->estadoInicial();

    dado = Dado::getInstance(debug);
    dado->setDebug(debug); // aunque no haria falta ya que en la misma instancia lo hacemos

    indiceJugadorActual = dado->quienEmpieza(nombres.size());

    Diario::getInstance()->ocurreEvento("Empezamos el juego: ¡Se lanza el dado!.");
    Diario::getInstance()->ocurreEvento("El primero en empezar es " + jugadores.at(indiceJugadorActual)->getNombre() + ".\n");

    mazo = new MazoSorpresa(debug);

    tablero = new Tablero();
    this->inicializaTablero(*mazo);

    this->InicializaMazoSorpresas();
}

void civitas::CivitasJuego::InicializaMazoSorpresas()
{
    mazo->alMazo(new SorpresaConvertirme("Convertir jugador", 0, mazo));
    mazo->alMazo(new SorpresaPagarCobrar("Paga al jugador de tu derecha 500", -500, mazo));
    mazo->alMazo(new SorpresaPagarCobrar("Paga al jugador de tu izquierda 500", -500, mazo));
    mazo->alMazo(new SorpresaPagarCobrar("Paga al jugador de en frente 500", -500, mazo));
    mazo->alMazo(new SorpresaPagarCobrar("Cobra al jugador de tu derecha 500", 500, mazo));
    mazo->alMazo(new SorpresaPagarCobrar("Cobra al jugador de tu izquierda 500", 500, mazo));
    mazo->alMazo(new SorpresaPagarCobrar("Cobra al jugador de en frente 500", 500, mazo));
    mazo->alMazo(new SorpresaCasaHotel("Paga por tu primera casa 500", -500, mazo));
    mazo->alMazo(new SorpresaCasaHotel("Paga por tu primer hotel 500", -500, mazo));
    mazo->alMazo(new SorpresaCasaHotel("Cobra por tu primera casa 500", 500, mazo));
    mazo->alMazo(new SorpresaCasaHotel("Cobra por tu primer hotel 500", 500, mazo));

}

void civitas::CivitasJuego::inicializaTablero(MazoSorpresa& mazo)
{
    tablero->añadeCasilla(new CasillaCalle("Calle jhonny", 1500, 500, 50));
    tablero->añadeCasilla(new CasillaCalle("Calle Guatemala", 2000, 200, 30));
    tablero->añadeCasilla(new CasillaCalle("Calle Grumete loco", 3000, 350, 45));
    tablero->añadeCasilla(new CasillaSorpresa("Sorpresa1", mazo));
    tablero->añadeCasilla(new CasillaCalle("Calle Capitan Chickens", 4000, 400, 40));
    tablero->añadeCasilla(new CasillaCalle("Calle gloria de Fenix", 5000, 222, 44));
    tablero->añadeCasilla(new CasillaSorpresa("Sorpresa", mazo));
    tablero->añadeCasilla(new CasillaCalle("Calle Cloaca ninja", 3000, 100, 25));
    tablero->añadeCasilla(new CasillaCalle("Calle lozano melosa", 1000, 100, 10));
    tablero->añadeCasilla(new Casilla("Parking"));
    tablero->añadeCasilla(new CasillaCalle("Calle Palomil", 4200, 320, 21));
    tablero->añadeCasilla(new CasillaCalle("Calle rioo bravoo", 3400, 220, 40));
    tablero->añadeCasilla(new CasillaSorpresa("Sorpresa2", mazo));
    tablero->añadeCasilla(new CasillaCalle("Avenida patin piti", 3200, 400, 200));
    tablero->añadeCasilla(new CasillaCalle("Rotonda los gansos", 5300, 500, 120));
    tablero->añadeCasilla(new CasillaSorpresa("Sorpresa3", mazo));
    tablero->añadeCasilla(new CasillaCalle("Calle resurgir del fenix", 2600, 200, 54));
    tablero->añadeCasilla(new CasillaCalle("Calle rosas", 3500, 320, 33));
    tablero->añadeCasilla(new CasillaCalle("Calle Sprinter", 2000, 400, 200));

}

void civitas::CivitasJuego::contabilizarPasosPorSalida(Jugador &JugadorActual)
{
    if (tablero->computarPasoPorSalida())
        JugadorActual.pasaPorSalida();
}

bool civitas::CivitasJuego::finalDelJuego()
{
    for (int i = 0; i < jugadores.size(); i++)
    {
        if (jugadores.at(i)->enBancarrota())
            return true;
    }

    return false;
}

void civitas::CivitasJuego::pasarTurno()
{
    if (indiceJugadorActual == jugadores.size() - 1)
        indiceJugadorActual = 0;
    else 
        indiceJugadorActual++;
}

vector<Jugador*> civitas::CivitasJuego::ranking()
{
    std::sort(jugadores.begin(), jugadores.end(), [](Jugador* lhs, Jugador* rhs) {
        return lhs->getSaldo() < rhs->getSaldo();
        });

    return jugadores;
}

void civitas::CivitasJuego::avanzaJugador()
{
    Jugador *jugadorActual = this->getJugadorActual();

    int posicionActual = jugadorActual->getCasillaActual();

    Diario::getInstance()->ocurreEvento("\n" + jugadorActual->getNombre() + " lanza el dado.");

    int tirada = dado->tirar();
    int posicionNueva = tablero->nuevaPosicion(posicionActual, tirada);

    Casilla *casilla = tablero->getCasilla(posicionNueva);

    Diario::getInstance()->ocurreEvento("Ha salido el numero: " + to_string(tirada) );
    Diario::getInstance()->ocurreEvento("Ha caido en la casilla: " + casilla->getNombre());

    this->contabilizarPasosPorSalida(*jugadorActual);

    jugadorActual->moverACasilla(posicionNueva);

    casilla->recibeJugador(indiceJugadorActual, jugadores);
}

OperacionJuego civitas::CivitasJuego::siguientePaso()
{
    Jugador *jugadorActual = this->getJugadorActual();
    OperacionJuego operacion = gs->siguienteOperacion(*jugadorActual, estado);

    if (operacion == OperacionJuego::PASAR_TURNO)
    {
        this->pasarTurno();
        this->siguientePasoCompletado(operacion);

    }
    else if (operacion == OperacionJuego::AVANZAR)
    {
        this->avanzaJugador();
        this->siguientePasoCompletado(operacion);
    }

    return operacion;
}

bool civitas::CivitasJuego::comprar()
{
    bool res;

    Jugador *jugadorActual = this->getJugadorActual();

    int numCasillaActual = jugadorActual->getCasillaActual();

    CasillaCalle *casilla = ((CasillaCalle*)tablero->getCasilla(numCasillaActual));

    res = jugadorActual->comprar(*casilla);

    return res;
}
