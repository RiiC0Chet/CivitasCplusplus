#include "VistaTextual.h"
#include "CasillaCalle.h"

using namespace vistaTextualCivitas;

VistaTextual::VistaTextual(CivitasJuego& juegoModel): Vista()
{
	separador = "=====================";
	this->juegoModel = &juegoModel;
}

void VistaTextual::pausa()
{
	cout << "Pulsa una tecla" << endl;
	cin >> basura;
}

int VistaTextual::leeEntero(int max, string msg1, string msg2)//pfff
{
    bool ok;
    string cadena;
    int numero = -1;
    do 
    {
        cout << (msg1)<<endl;
        cin >> cadena;
        try 
        {
            numero = stoi(cadena);
            ok = true;
            if (!(!cadena.empty() && std::find_if(cadena.begin(),
                cadena.end(), [](unsigned char c) { return !std::isdigit(c); }) == cadena.end())) // comprobamos si no se ha introducido un entero
                throw 404;
        }
        catch (int n) 
        { // No se ha introducido un entero
            cout << (msg2)<<endl;
            ok = false;
        }
        if (ok && (numero < 0 || numero >= max)) 
        {
            cout << (msg2)<<endl;
            ok = false;
        }
    } while (!ok);

    return numero;
}

int VistaTextual::menu(string titulo, vector<string> lista)
{
    string tab = "  ";
    int opcion;
    cout << (titulo)<<endl;
    for (int i = 0; i < lista.size(); i++) {
        cout << (tab + to_string(i) + "-" + lista.at(i))<<endl;
    }

    opcion = leeEntero(lista.size(),
        "\n" + tab + "Elige una opcion: ",
        tab + "Valor erroneo");
    return opcion;
}

void VistaTextual::actualiza()
{
    cout << (juegoModel->getJugadorActual()->toString())<<endl;

    if (juegoModel->finalDelJuego()) 
    {
        vector<Jugador*> jugadores = juegoModel->_ranking();
        cout << ("Juego terminado: Ranking de Jugadores")<<endl;

        for (int i = 0; i < jugadores.size(); i++)
            cout << (i + 1 + ". " + jugadores.at(i)->toString())<<endl;

    }
}

controladorCivitas::Respuesta VistaTextual::comprar()
{
    string titulo = "¿Desea comprar la calle?";
    vector<string> opciones;
    opciones.push_back("NO");
    opciones.push_back("SI");

    int opcion = menu(titulo, opciones);
    controladorCivitas::Respuesta seleccion;

    if (opcion == 1)
        seleccion = controladorCivitas::Respuesta::SI;
    else 
        seleccion = controladorCivitas::Respuesta::NO;

    return seleccion;
}

OperacionInmobiliaria VistaTextual::elegirOperacion()
{
    string titulo = "¿Que numero de gestion inmobiliaria ha escogido?";
    vector<string> opciones ;
    opciones.push_back("CONSTRUIR_CASA ");
    opciones.push_back("CONSTRUIR_HOTEL ");
    opciones.push_back("TERMINAR");

    int opcion = menu(titulo, opciones);
    OperacionInmobiliaria aux = static_cast<OperacionInmobiliaria>(opcion);// OK but probably a bug
    return aux;
}

int VistaTextual::elegirPropiedad()
{
    int indicePropiedad = 0;

    string titulo = "Elige una propiedad: ";
    vector<CasillaCalle*> propiedades = juegoModel->getJugadorActual()->getPropiedades();

    vector<string> opciones;

    for (int i = 0; i < propiedades.size(); i++)
        opciones.push_back(propiedades.at(i)->toString());

    int opcion = menu(titulo, opciones);

    return opcion;
}

void VistaTextual::mostrarEventos()
{
    while (Diario::getInstance()->eventosPendientes()) {
        Diario::getInstance()->leerEvento();
    }
}

void VistaTextual::mostrarEstado()
{
    if (!juegoModel->finalDelJuego())
    {
        string nombre = juegoModel->getJugadorActual()->toString();
        int casilla_actual = juegoModel->getJugadorActual()->_getCasillaActual();
        cout << ("Estado actual:")<<endl;
        cout << (nombre)<<endl;
        cout.flush();
        cout << ("Casilla: " + to_string(casilla_actual) )<<endl;


    }
    else {

        vector<Jugador*> jugadores = juegoModel->_ranking();
        cout << ("Juego terminado: Ranking de Jugadores")<<endl;

        for (int i = 0; i < jugadores.size(); i++)
            cout << (i + 1 + ". " + jugadores.at(i)->toString())<<endl;


    }
}

VistaTextual::~VistaTextual()
{
    delete[] juegoModel;
}