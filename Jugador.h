//#pragma once
#include <string>
#include <vector>
//#include "CasillaCalle.h"

#ifndef JUGADOR_H
#define JUGADOR_H

using namespace std;

namespace civitas
{
	class Jugador
	{
        private:           
    
            const static int SALDOINICIAL = 7500;
            
            int casillaActual;
            string nombre;
            
            float saldo;

            vector< CasillaCalle* > propiedades;

            /*
            * @brief  Funcion para comprobar si una propiedad es nuestra
            * @param  ip, posicion donde se encuentra la casilla
            * @return  bool, true si existe y es nuestra false si no
            */
            bool existeLaPropiedad(int ip);

            /**  
             * 
             * @brief funcion para comprobar si se puede Edificar
             *        una casa o no
             * @param propiedad, de tipo Casillacalle en la que 
             *        se quiere edificar
             * @return bool, true si se puede efificar o no
             */
            bool puedoEdificarCasa(CasillaCalle &propiedad);


            /**
             *
             * @brief funcion para comprobar si se puede Edificar
             *        un hotel o no
             * @param propiedad, de tipo Casillacalle en la que
             *        se quiere edificar
             * @return bool, true si se puede efificar o no
             */
            bool puedoEdificarHotel(CasillaCalle &propiedad);

        // Variables protegidas
        protected:
            const static int CASASMAX = 4;
            const static int CASASPORHOTEL = 4;
            const static int HOTELESMAX = 4;

            const static int PASOPORSALIDA = 1000;
            bool puedeComprar;

            /**
             * @brief de copia con otro jugador, protegido
             *        para poder ser accedido desde clases hijas
             * 
             * @param otro, de tipo Jugador
             */
            Jugador(Jugador &otro);
            /**
             * 
             * @brief Funcion con la que convertimosjugadores a JugadoresEspeculadores
             * 
             * @return JugadorEspeculador
             */
            JugadorEspeculador& convertir();
        public:
            Jugador(string nombre);
            int cantidadCasasHoteles();
            int compareTo(Jugador &otro);
            bool comprar(CasillaCalle &titulo);
            bool construirCasa(int ip);
            bool construirHotel(int ip);
            bool enBancarrota();
            bool existeLaPropiedad(int ip);

            inline const int getCasasMax() 
            {
                return CASASMAX;
            }

            inline const int getCASASPORHOTEL() 
            {
                return CASASPORHOTEL;
            }

            inline int getCasillaActual() 
            {
                return casillaActual;
            }

            inline int _getCasillaActual() 
            {
                return casillaActual;
            }

            inline const int getHOTELESMAX() 
            {
                return HOTELESMAX;
            }

            inline string getNombre() 
            {
                return nombre;
            }

            inline const float getPremioPasoSalida() 
            {
                return PASOPORSALIDA;
            }

            inline vector<CasillaCalle*> getPropiedades() 
            {
                return propiedades;
            }

            inline bool getPuedeComprar() 
            {
                return puedeComprar;
            }

            inline float getSaldo() 
            {
                return saldo;
            }

            float modificarSaldo(float cantidad);
            bool moverACasilla(int num_Casilla);
            float paga(float cantidad);
            float pagaAlquiler(float cantidad);
            bool pasaPorSalida();
            bool puedeComprarCasilla();
            bool puedoGastar(float precio);
            float recibe(float cantidad);
            bool tieneAlgoQueGestionar();

            inline bool esEspeculador() 
            {
                return false;
            }

            inline string toString()
            {
                return ("Nombre: " + nombre + ". Saldo: " + to_string(saldo) + ". Posicion: " + to_string(casillaActual) + ". Num Propiedades: " + to_string(propiedades.size()) );
            }
	};

}

#endif