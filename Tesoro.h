/* Tesoro.h Laboratorio 2
 * Author: Jorge Sanchez Vargas A95819 */

#ifndef TESORO_H_
#define TESORO_H_

//#include <stdlib.h>
#include "Moneda.h"
#include "Anillo.h"
#include "Corona.h"
#include "Collar.h"
#include <cstdlib>
#include <utility>
#include <time.h>
using namespace std;

class Tesoro{

	friend class Pirata;

	private:
		//Rangos de Monedas:
		pair <int, int> cantidadDeMonedas = {5, 10};
		pair <int, int> valoresDeMonedas {1, 100};
		pair <int, int> pesoDeMonedas = {100, 200};
		//Rangos de Collares:
		pair <int, int> cantidadDeCollares = {2, 5};
		pair <int, int> valoresDeCollares = {2000, 4000};
		pair <int, int> pesoDeCollares = {500, 1000};
		//Rangos de Coronas:
		pair <int, int> cantidadDeCoronas = {1, 5};
		pair <int, int> valoresDeCoronas = {1000, 10000};
		pair <int, int> pesoDeCoronas = {500, 2000};
		//Rangos de Anillos:
		pair <int, int> cantidadDeAnillos = {5, 7};
		pair <int, int> valoresDeAnillos = {100, 200};
		pair <int, int> pesoDeAnillos = {200, 300};

		int tamañoArregloMonedas;
		int tamañoArregloCollares;
		int tamañoArregloCoronas;
		int tamañoArregloAnillos;

		Moneda * arregloMonedas;
		Collar * arregloCollares;
		Corona * arregloCoronas;
		Anillo * arregloAnillos;

		int totalObjetosEnTesoro;
		pair<char, double> * tesoroOrdenado;

		void generarArregloOrdenado();
		int generarRandom(int, int);

	public:
		void imprimirTesoro();
		Tesoro();
		~Tesoro();
};

#endif /* TESORO_H_ */
