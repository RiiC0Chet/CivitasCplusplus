
#ifndef MAZOSORPRESA_H
#define MAZOSORPRESA_H

#include <vector>
//#include "Diario.h"
#include "sorpresa.h"



using namespace std;
namespace civitas
{
	class MazoSorpresa
	{
		private:
			vector<Sorpresa*> sorpresas;

			bool barajada;
			int usadas;
			bool debug;

			void init();
		public:
			MazoSorpresa(bool d);
			MazoSorpresa();
			void alMazo(Sorpresa *s);
			Sorpresa* siguiente();

			~MazoSorpresa();
	};

}

#endif