/* Main.cpp Laboratorio 2
 * Author: Jorge Sanchez Vargas A95819 */

#ifndef PIRATA_H_
#define PIRATA_H_

#include <utility>
#include <array>
#include <cstdlib>
#include <cstdlib>
#include <utility>
#include <time.h>
#include "Moneda.h"
#include "Anillo.h"
#include "Corona.h"
#include "Collar.h"
using namespace std;

class Pirata{

	private:
		pair <int, int> rangoDeSaco = {1000, 2000};
		int tamanoDelSaco;
		int valorDelBotin;
		int pesoDelBotin;
		void robarMoneda(Moneda);
		void robarCollar(Collar);
		void robarCorona(Corona);
		void robarAnillo(Anillo);

	public:

		Pirata();
		~Pirata();

		void Robar(Moneda[], Collar[], Corona[], Anillo[], pair<char,double>[], int);

};

#endif /* PIRATA_H_ */
