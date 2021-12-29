
#ifndef DIARIO_H
#define DIARIO_H

#include <string>
#include <vector>


using namespace std;

namespace civitas
{
	class Diario
	{
		private:
			//static Diario* instance;
			vector<string> eventos;
			//GestorEstados gs = new GestorEstados();

			// Constructores singleton privados
			inline Diario()
			{
				//this->instance = nullptr;
			}

		public:

			//Un singleton no ha de ser clonable
			Diario(Diario&) = delete;
			//Un singleton no ha de ser asignable
			void operator=(const Diario&) = delete;

			static Diario* getInstance();
			
			inline vector<string> getEventos() 
			{
				return eventos;
			}

			inline void ocurreEvento(string e)
			{
				eventos.push_back(e);
			}

			inline bool eventosPendientes() 
			{
				return !eventos.empty();
			}
			string leerEvento();
	};
}


#endif