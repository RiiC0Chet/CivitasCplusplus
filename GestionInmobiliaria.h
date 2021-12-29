#ifndef GESTIONINMOBILIARIA_H
#define GESTIONINMOBILIARIA_H

#include "OperacionInmobiliaria.h"

namespace civitas
{
	class GestionInmobiliaria
	{
		private:
			int propiedad;
			OperacionInmobiliaria operacion;
		public:
			GestionInmobiliaria(OperacionInmobiliaria gest, int ip);
			
			inline OperacionInmobiliaria getOperacion() 
			{
				return operacion;
			}

			inline int getPropiedad() 
			{

				return propiedad;
			}
	};
}


#endif