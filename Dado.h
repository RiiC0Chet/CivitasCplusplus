
#ifndef DADO_H
#define DADO_H

#include "Diario.h"



namespace civitas
{
	class Dado
	{
		private:

			int ultimoResultado;
			bool debug;

			// Constructor privado en clases singletong
			Dado(bool d);
		public:
			
			//Un singleton no ha de ser clonable
			Dado(Dado&) = delete;
			//Un singleton no ha de ser asignable
			void operator=(const Dado&) = delete;

			static Dado* getInstance(bool d);
			int tirar();
			int quienEmpieza(int n);
			void setDebug(bool d);

			inline int getUltimoResultado()
			{
				return ultimoResultado;
			}
	};
}


#endif