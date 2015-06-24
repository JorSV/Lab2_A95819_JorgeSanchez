/* Main.cpp Laboratorio 2
 * Author: Jorge Sanchez Vargas A95819 */
#include "Tesoro.h"
#include "Pirata.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char **argv) {

	Tesoro tesoro;
	Pirata pirata;

	tesoro.imprimirTesoro();	

	pirata.robarRecursivo(tesoro, 0);
	pirata.imprimirEstadoFinal();

	pirata.reiniciarValores();

	pirata.robarNoRecursivo(tesoro, 0);
	pirata.imprimirEstadoFinal();
	//system("pause");

	return 0;
}
