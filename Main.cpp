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

	//Crea los arreglos de los tipos de tesoro de tamaño random:

	int tamañoArregloMonedas = tesoro.generarRandom(tesoro.cantidadDeMonedas.first, tesoro.cantidadDeMonedas.second - tesoro.cantidadDeMonedas.first);
	int tamañoArregloCollares = tesoro.generarRandom(tesoro.cantidadDeCollares.first, tesoro.cantidadDeCollares.second - tesoro.cantidadDeCollares.first);
	int tamañoArregloCoronas = tesoro.generarRandom(tesoro.cantidadDeCoronas.first, tesoro.cantidadDeCoronas.second - tesoro.cantidadDeCoronas.first);
	int tamañoArregloAnillos = tesoro.generarRandom(tesoro.cantidadDeAnillos.first, tesoro.cantidadDeAnillos.second - tesoro.cantidadDeAnillos.first);

	Moneda * arregloMonedas = new Moneda[tamañoArregloMonedas];
	Collar * arregloCollares = new Collar[tamañoArregloCollares];
	Corona * arregloCoronas = new Corona[tamañoArregloCoronas];
	Anillo * arregloAnillos = new Anillo[tamañoArregloAnillos];

	tesoro.totalObjetosEnTesoro = tamañoArregloMonedas + tamañoArregloCollares + tamañoArregloCoronas + tamañoArregloAnillos;
	
	cout << tesoro.totalObjetosEnTesoro << endl;

	//Crea in arreglo tipo pair del tamaño do los arreglos Moneda, Collar, Corona y Anillo sumados.
	pair<char, double> * tesoroOrdenado = new pair<char, double>[tesoro.totalObjetosEnTesoro];

	//Ingresa al arreglo general todos los "valores reales" de los tesoros identificandolos por tipo con un char: M=Moneda, L=Collar, R=Corona, A=Anillo
	for (int t=0; t<tesoro.totalObjetosEnTesoro;){

		//Le da valores y peso random al los objetos Moneda y calcula sus "valores reales" (valor/peso):
		for (int i = 0; i<tamañoArregloMonedas; i++){
			arregloMonedas[i].asignarValor( tesoro.generarRandom(tesoro.valoresDeMonedas.first, tesoro.valoresDeMonedas.second-tesoro.valoresDeMonedas.first));
			arregloMonedas[i].asignarPeso( tesoro.generarRandom(tesoro.pesoDeMonedas.first, tesoro.pesoDeMonedas.second-tesoro.pesoDeMonedas.first));
			arregloMonedas[i].calcularValorReal();
			tesoroOrdenado[t].first='M';
			tesoroOrdenado[t].second=arregloMonedas[i].obtenerValorReal();
			t++;
		}

		//Le da valores y peso random al los objetos Collar y calcula sus "valores reales" (valor/peso):
		for (int i = 0; i<tamañoArregloCollares; i++){
			arregloCollares[i].asignarValor( tesoro.generarRandom(tesoro.valoresDeCollares.first, tesoro.valoresDeCollares.second-tesoro.valoresDeCollares.first));
			arregloCollares[i].asignarPeso( tesoro.generarRandom(tesoro.pesoDeCollares.first, tesoro.pesoDeCollares.second-tesoro.pesoDeCollares.first));
			arregloCollares[i].calcularValorReal();
			tesoroOrdenado[t].first='L';
			tesoroOrdenado[t].second=arregloCollares[i].obtenerValorReal();
			t++;
		}

		//Le da valores y peso random al los objetos Corona y calcula sus "valores reales" (valor/peso):
		for (int i = 0; i<tamañoArregloCoronas; i++){
			arregloCoronas[i].asignarValor( tesoro.generarRandom(tesoro.valoresDeCoronas.first, tesoro.valoresDeCoronas.second-tesoro.valoresDeCoronas.first));
			arregloCoronas[i].asignarPeso( tesoro.generarRandom(tesoro.pesoDeCoronas.first, tesoro.pesoDeCoronas.second-tesoro.pesoDeCoronas.first));
			arregloCoronas[i].calcularValorReal();
			tesoroOrdenado[t].first='R';
			tesoroOrdenado[t].second=arregloCoronas[i].obtenerValorReal();
			t++;
		}

		//Le da valores y peso random al los objetos Anillo y calcula sus "valores reales" (valor/peso):
		for (int i = 0; i<tamañoArregloAnillos; i++){
			arregloAnillos[i].asignarValor( tesoro.generarRandom(tesoro.valoresDeAnillos.first, tesoro.valoresDeAnillos.second-tesoro.valoresDeAnillos.first));
			arregloAnillos[i].asignarPeso( tesoro.generarRandom(tesoro.pesoDeAnillos.first, tesoro.pesoDeAnillos.second-tesoro.pesoDeAnillos.first));
			arregloAnillos[i].calcularValorReal();
			tesoroOrdenado[t].first='A';
			tesoroOrdenado[t].second=arregloAnillos[i].obtenerValorReal();
			t++;
		}

	}

	//ordena el arreglo de pairs que contiene los "valores reales" por el metodo de burbuja
	pair<char, double> aux;
	for (int i = 0; i<tesoro.totalObjetosEnTesoro; i++){
		for (int j = 0; j<tesoro.totalObjetosEnTesoro; j++){
			if (tesoroOrdenado[i].second >= tesoroOrdenado[j].second){
				aux= tesoroOrdenado[j];
				tesoroOrdenado[j] = tesoroOrdenado[i];
				tesoroOrdenado[i] = aux;
			}
		}
	}

	ofstream archivoTesoro("tesoro.txt");

	archivoTesoro << "Monedas: " << endl;
	for (int i = 0; i<tamañoArregloMonedas; i++){
		archivoTesoro << "Moneda " << i+1 << ": " << "valor: "  << arregloMonedas[i].obtenerValor() << ", Peso: " << arregloMonedas[i].obtenerPeso() << ", ID unico: " << arregloMonedas[i].obtenerID() << endl;
	}

	archivoTesoro << "Collares: " << endl;
	for (int i = 0; i<tamañoArregloCollares; i++){
		archivoTesoro << "Collar " << i+1 << ": " << "valor: "  << arregloCollares[i].obtenerValor() << ", Peso: " << arregloCollares[i].obtenerPeso() << ", ID unico: " << arregloCollares[i].obtenerID() << endl;
	}

	archivoTesoro << "Coronas: " << endl;
	for (int i = 0; i<tamañoArregloCoronas; i++){
		archivoTesoro << "Corona " << i+1 << ": " << "valor: "  << arregloCoronas[i].obtenerValor() << ", Peso: " << arregloCoronas[i].obtenerPeso() << ", ID unico: " << arregloCoronas[i].obtenerID() << endl;
	}

	archivoTesoro << "Anillos: " << endl;
	for (int i = 0; i<tamañoArregloAnillos; i++){
		archivoTesoro << "Anillo " << i+1 << ": " << "valor: "  << arregloAnillos[i].obtenerValor() << ", Peso: " << arregloAnillos[i].obtenerPeso() << ", ID unico: " << arregloAnillos[i].obtenerID() << endl;
	}

	archivoTesoro.close();

	/*ofstream archivoTesoroOrdenado("tesoroOrdenado.txt");
	for (int i = 0; i<tesoro.totalObjetosEnTesoro; i++){
		archivoTesoroOrdenado << "Tipo de tesoro: " << tesoroOrdenado[i].first << ", Valor Real: " << tesoroOrdenado[i].second << endl;
	}
	archivoTesoroOrdenado.close();*/

	pirata.Robar(arregloMonedas, arregloCollares, arregloCoronas, arregloAnillos, tesoroOrdenado, 0);

	system("pause");

	return 0;
}
