/* Main.cpp Laboratorio 2
 * Author: Jorge Sanchez Vargas A95819 */
#include "Tesoro.h"
#include "Pirata.h"
#include <chrono>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
using namespace std;
using chrono::milliseconds;
using chrono::duration_cast;

int main(int argc, char **argv) {

	Tesoro tesoro;
	Pirata pirata;

	/*tesoro.imprimirTesoro();

	pirata.robarRecursivo(tesoro, 0);
	pirata.imprimirEstadoFinal();

	pirata.reiniciarValores();

	pirata.robarNoRecursivo(tesoro, 0);
	pirata.imprimirEstadoFinal();*/


	for (int i = 0; i < 30; i++){
		Tesoro tesoro;

		auto inicioRecursivo = chrono::high_resolution_clock::now();
		pirata.reiniciarValores();
		pirata.robarRecursivo(tesoro, 0);
		pirata.imprimirEstadoFinal();
		auto finRecursivo = chrono::high_resolution_clock::now();
		milliseconds ms1 = duration_cast<milliseconds>(inicioRecursivo - finRecursivo);
		cout << "La duracion del metodo recursivo fue de " << ms1.count() << " miliseg. en la corrida numero " << i << endl;

		auto inicioNoRecursivo = chrono::high_resolution_clock::now();
		pirata.reiniciarValores();
		pirata.robarNoRecursivo(tesoro, 0);
		pirata.imprimirEstadoFinal();
		auto finNoRecursivo = chrono::high_resolution_clock::now();
		milliseconds ms2 = duration_cast<milliseconds>(inicioNoRecursivo - finNoRecursivo);
		cout << "La duracion del metodo no recursivo fue de " << ms2.count() << " miliseg. en la corrida numero " << i << endl;

		cout << endl;
	}

	system("pause");

	return 0;
}
