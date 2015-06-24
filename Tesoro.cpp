/* Tesoro.cpp Laboratorio 2
 * Author: Jorge Sanchez Vargas A95819 */

#include "Tesoro.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>

Tesoro::Tesoro(){
	totalObjetosEnTesoro = 0;
	srand (time(0));

	//Establece los tama�os random:
	tama�oArregloMonedas = generarRandom(cantidadDeMonedas.first, cantidadDeMonedas.second - cantidadDeMonedas.first);
	tama�oArregloCollares = generarRandom(cantidadDeCollares.first, cantidadDeCollares.second - cantidadDeCollares.first);
	tama�oArregloCoronas = generarRandom(cantidadDeCoronas.first, cantidadDeCoronas.second - cantidadDeCoronas.first);
	tama�oArregloAnillos = generarRandom(cantidadDeAnillos.first, cantidadDeAnillos.second - cantidadDeAnillos.first);

	//Crea los arreglos de los tipos de tesoro de tama�o establecido anteriormente
	arregloMonedas = new Moneda[tama�oArregloMonedas];
	arregloCollares = new Collar[tama�oArregloCollares];
	arregloCoronas = new Corona[tama�oArregloCoronas];
	arregloAnillos = new Anillo[tama�oArregloAnillos];

	totalObjetosEnTesoro = tama�oArregloMonedas + tama�oArregloCollares + tama�oArregloCoronas + tama�oArregloAnillos;

	//Crea in arreglo tipo pair del tama�o do los arreglos Moneda, Collar, Corona y Anillo sumados.
	tesoroOrdenado = new pair<char, double>[totalObjetosEnTesoro];

	generarArregloOrdenado();
}

Tesoro::~Tesoro(){
}

void Tesoro::generarArregloOrdenado(){

	//Ingresa al arreglo general todos los "valores reales" de los tesoros identificandolos por tipo con un char: M=Moneda, L=Collar, R=Corona, A=Anillo
	for (int t = 0; t<totalObjetosEnTesoro;){

		//Le da valores y peso random al los objetos Moneda y calcula sus "valores reales" (valor/peso):
		for (int i = 0; i<tama�oArregloMonedas; i++){
			arregloMonedas[i].asignarValor(generarRandom(valoresDeMonedas.first, valoresDeMonedas.second - valoresDeMonedas.first));
			arregloMonedas[i].asignarPeso(generarRandom(pesoDeMonedas.first, pesoDeMonedas.second - pesoDeMonedas.first));
			arregloMonedas[i].calcularValorReal();
			tesoroOrdenado[t].first = 'M';
			tesoroOrdenado[t].second = arregloMonedas[i].obtenerValorReal();
			t++;
		}

		//Le da valores y peso random al los objetos Collar y calcula sus "valores reales" (valor/peso):
		for (int i = 0; i<tama�oArregloCollares; i++){
			arregloCollares[i].asignarValor(generarRandom(valoresDeCollares.first, valoresDeCollares.second - valoresDeCollares.first));
			arregloCollares[i].asignarPeso(generarRandom(pesoDeCollares.first, pesoDeCollares.second - pesoDeCollares.first));
			arregloCollares[i].calcularValorReal();
			tesoroOrdenado[t].first = 'L';
			tesoroOrdenado[t].second = arregloCollares[i].obtenerValorReal();
			t++;
		}

		//Le da valores y peso random al los objetos Corona y calcula sus "valores reales" (valor/peso):
		for (int i = 0; i<tama�oArregloCoronas; i++){
			arregloCoronas[i].asignarValor(generarRandom(valoresDeCoronas.first, valoresDeCoronas.second - valoresDeCoronas.first));
			arregloCoronas[i].asignarPeso(generarRandom(pesoDeCoronas.first, pesoDeCoronas.second - pesoDeCoronas.first));
			arregloCoronas[i].calcularValorReal();
			tesoroOrdenado[t].first = 'R';
			tesoroOrdenado[t].second = arregloCoronas[i].obtenerValorReal();
			t++;
		}

		//Le da valores y peso random al los objetos Anillo y calcula sus "valores reales" (valor/peso):
		for (int i = 0; i<tama�oArregloAnillos; i++){
			arregloAnillos[i].asignarValor(generarRandom(valoresDeAnillos.first, valoresDeAnillos.second - valoresDeAnillos.first));
			arregloAnillos[i].asignarPeso(generarRandom(pesoDeAnillos.first, pesoDeAnillos.second - pesoDeAnillos.first));
			arregloAnillos[i].calcularValorReal();
			tesoroOrdenado[t].first = 'A';
			tesoroOrdenado[t].second = arregloAnillos[i].obtenerValorReal();
			t++;
		}

	}

	//ordena el arreglo de pairs que contiene los "valores reales" por el metodo de burbuja
	pair<char, double> aux;
	for (int i = 0; i<totalObjetosEnTesoro; i++){
		for (int j = 0; j<totalObjetosEnTesoro; j++){
			if (tesoroOrdenado[i].second >= tesoroOrdenado[j].second){
				aux = tesoroOrdenado[j];
				tesoroOrdenado[j] = tesoroOrdenado[i];
				tesoroOrdenado[i] = aux;
			}
		}
	}

}


void Tesoro::imprimirTesoro(){

	ofstream archivoTesoro("tesoro.txt");

	archivoTesoro << "Monedas: " << endl;
	for (int i = 0; i<tama�oArregloMonedas; i++){
		archivoTesoro << "Moneda " << i + 1 << ": " << "valor: " << arregloMonedas[i].obtenerValor() << ", Peso: " << arregloMonedas[i].obtenerPeso() << ", ID unico: " << arregloMonedas[i].obtenerID() << endl;
	}

	archivoTesoro << "Collares: " << endl;
	for (int i = 0; i<tama�oArregloCollares; i++){
		archivoTesoro << "Collar " << i + 1 << ": " << "valor: " << arregloCollares[i].obtenerValor() << ", Peso: " << arregloCollares[i].obtenerPeso() << ", ID unico: " << arregloCollares[i].obtenerID() << endl;
	}

	archivoTesoro << "Coronas: " << endl;
	for (int i = 0; i<tama�oArregloCoronas; i++){
		archivoTesoro << "Corona " << i + 1 << ": " << "valor: " << arregloCoronas[i].obtenerValor() << ", Peso: " << arregloCoronas[i].obtenerPeso() << ", ID unico: " << arregloCoronas[i].obtenerID() << endl;
	}

	archivoTesoro << "Anillos: " << endl;
	for (int i = 0; i<tama�oArregloAnillos; i++){
		archivoTesoro << "Anillo " << i + 1 << ": " << "valor: " << arregloAnillos[i].obtenerValor() << ", Peso: " << arregloAnillos[i].obtenerPeso() << ", ID unico: " << arregloAnillos[i].obtenerID() << endl;
	}

	archivoTesoro.close();

	/*ofstream archivoTesoroOrdenado("tesoroOrdenado.txt");
	for (int i = 0; i<totalObjetosEnTesoro; i++){
	archivoTesoroOrdenado << "Tipo de tesoro: " << tesoroOrdenado[i].first << ", Valor Real: " << tesoroOrdenado[i].second << endl;
	}
	archivoTesoroOrdenado.close();*/
}

int Tesoro::generarRandom(int piso, int techo){
	return  rand() % techo + piso;
}
