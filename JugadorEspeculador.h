#pragma once
#include "Jugador.h"
#include <string>
using namespace std;

namespace civitas
{
	class JugadorEspeculador : public Jugador
	{
		private:
			static const int FACTORESPECULADOR = 2;
		protected:
			inline JugadorEspeculador(string nombre) : Jugador(nombre) {}

            inline JugadorEspeculador(Jugador otro): Jugador(otro)
            {
                actualizaPropiedadesPorConversion(*this);
            }

            inline JugadorEspeculador* convertir()
            {
                Diario::getInstance()->ocurreEvento("El jugador " + getNombre() + " ya es un especulador.");
                return nullptr;
            }
		public:
            inline int getHOTELESMAX() 
            {
                return HOTELESMAX * FACTORESPECULADOR;
            }

            
            inline int getCasasMax() 
            {
                return CASASMAX * FACTORESPECULADOR;
            }

            
            inline float paga(float cantidad) 
            {
                return modificarSaldo((cantidad / FACTORESPECULADOR) * (-1));
            }

            void actualizaPropiedadesPorConversion(Jugador &jugador);
            bool comprar(CasillaCalle &titulo);

            inline bool esEspeculador() 
            {
                return true;
            }

            
            inline string toString()
            {
                return (Jugador::toString() + " Es un jugador especulador.");
            }
	};
}


