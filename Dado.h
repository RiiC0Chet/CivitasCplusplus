#pragma once
#include "Diario.h"

namespace civitas
{
	class Dado
	{
		private:
			const static Dado *instance;

			int ultimoResultado;
			bool debug;

			// Constructor privado en clases singletong
			Dado(bool d);
		public:
			
			//Un singleton no ha de ser clonable
			Dado(Dado& otroDado) = delete;
			//Un singleton no ha de ser asignable
			void operator=(const Dado&) = delete;

			static const Dado* getInstance(bool d);
			int tirar();
			int quienEmpieza(int n);
			void setDebug(bool d);

			inline int getUltimoResultado()
			{
				return ultimoResultado;
			}
	};
}


