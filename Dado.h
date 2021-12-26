#pragma once

namespace civitas
{
	class Dado
	{
		private:
			const static Dado *instance;

			int ultimoResultado;
			bool debug;
		public:
			Dado(bool d);

			//Un singleton no ha de ser clonable
			Dado(Dado& otroDado) = delete;
			//Un singleton no ha de ser asignable
			void operator=(const Dado&) = delete;

			static const Dado* getInstance(bool d);

	};
}


