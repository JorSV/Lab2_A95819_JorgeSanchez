/* Main.cpp Laboratorio 2
 * Author: Jorge Sanchez Vargas A95819 */

#include "Pirata.h"
#include <iostream>
#include <fstream>

Pirata::Pirata()  {
	//srand (time(0));
	tamanoDelSaco = rand() % rangoDeSaco.first + (rangoDeSaco.second-rangoDeSaco.first);
	espacioRestanteEnSaco = tamanoDelSaco;
	valorDelBotin = 0;
	pesoDelBotin = 0;
	ofstream archivoBotinR("robado-recursivo.txt");
	ofstream archivoBotinNR("robado-no-recursivo.txt");
}

Pirata::~Pirata(){
}

void Pirata::robarMoneda(Moneda monedaRobada){
	ofstream archivoBotin;

	if (ejecutandoseRecursivo){
		archivoBotin.open("robado-recursivo.txt", ofstream::app);
	}
	else{
		archivoBotin.open("robado-no-recursivo.txt", ofstream::app);
	}

	archivoBotin << "Moneda Robada: " << monedaRobada.obtenerID() << ", Valor: " << monedaRobada.obtenerValor() << ", Peso:" << monedaRobada.obtenerPeso() << endl;
	archivoBotin.close();

	valorDelBotin = valorDelBotin+monedaRobada.obtenerValor();
	pesoDelBotin = pesoDelBotin+monedaRobada.obtenerPeso();
	espacioRestanteEnSaco = espacioRestanteEnSaco - monedaRobada.obtenerPeso();
}

void Pirata::robarCollar(Collar collarRobado){
	ofstream archivoBotin;

	if (ejecutandoseRecursivo){
		archivoBotin.open("robado-recursivo.txt", ofstream::app);
	}
	else{
		archivoBotin.open("robado-no-recursivo.txt", ofstream::app);
	}

	archivoBotin << "Collar Robado: " << collarRobado.obtenerID() << ", Valor: " << collarRobado.obtenerValor() << ", Peso:" << collarRobado.obtenerPeso() << endl;
	archivoBotin.close();

	valorDelBotin = valorDelBotin+collarRobado.obtenerValor();
	pesoDelBotin = pesoDelBotin+collarRobado.obtenerPeso();
	espacioRestanteEnSaco = espacioRestanteEnSaco - collarRobado.obtenerPeso();
}

void Pirata::robarCorona(Corona coronaRobada){
	ofstream archivoBotin;

	if (ejecutandoseRecursivo){
		archivoBotin.open("robado-recursivo.txt", ofstream::app);
	}
	else{
		archivoBotin.open("robado-no-recursivo.txt", ofstream::app);
	}

	archivoBotin << "Corona Robada: " << coronaRobada.obtenerID() << ", Valor: " << coronaRobada.obtenerValor() << ", Peso:" << coronaRobada.obtenerPeso() << endl;
	archivoBotin.close();

	valorDelBotin = valorDelBotin+coronaRobada.obtenerValor();
	pesoDelBotin = pesoDelBotin+coronaRobada.obtenerPeso();
	espacioRestanteEnSaco = espacioRestanteEnSaco - coronaRobada.obtenerPeso();
}

void Pirata::robarAnillo(Anillo anilloRobado){
	ofstream archivoBotin;

	if (ejecutandoseRecursivo){
		archivoBotin.open("robado-recursivo.txt", ofstream::app);
	}
	else{
		archivoBotin.open("robado-no-recursivo.txt", ofstream::app);
	}

	archivoBotin << "Anillo Robado: " << anilloRobado.obtenerID() << ", Valor: " << anilloRobado.obtenerValor() << ", Peso:" << anilloRobado.obtenerPeso() << endl;
	archivoBotin.close();

	valorDelBotin = valorDelBotin+anilloRobado.obtenerValor();
	pesoDelBotin = pesoDelBotin+anilloRobado.obtenerPeso();
	espacioRestanteEnSaco = espacioRestanteEnSaco - anilloRobado.obtenerPeso();
}

bool Pirata::robar(Tesoro tesoro, int punteroDeTesoroOrdenado){

	char tipoDeTesoroApuntado;// = 0;

	tipoDeTesoroApuntado = tesoro.tesoroOrdenado[punteroDeTesoroOrdenado].first;
	bool continuar = true;
	int i = 0;

	switch (tipoDeTesoroApuntado){
	case 'M':
		while (continuar){
			if (tesoro.arregloMonedas[i].obtenerValorReal() == tesoro.tesoroOrdenado[punteroDeTesoroOrdenado].second){
				if (espacioRestanteEnSaco - tesoro.arregloMonedas[i].obtenerPeso() < 1 || tesoro.arregloMonedas[i].obtenerPeso() == 0){
					continuar = false;
				}
				else{
					robarMoneda(tesoro.arregloMonedas[i]);
					continuar = false;
				}
			}
			i++;
		}
		break;

	case 'L':
		while (continuar){
			if (tesoro.arregloCollares[i].obtenerValorReal() == tesoro.tesoroOrdenado[punteroDeTesoroOrdenado].second){
				if (espacioRestanteEnSaco - tesoro.arregloCollares[i].obtenerPeso() < 1 || tesoro.arregloCollares[i].obtenerPeso() == 0){
					continuar = false;
				}
				else{
					robarCollar(tesoro.arregloCollares[i]);
					continuar = false;
				}
			}
			i++;
		}
		break;

	case 'R':
		while (continuar){
			if (tesoro.arregloCoronas[i].obtenerValorReal() == tesoro.tesoroOrdenado[punteroDeTesoroOrdenado].second){
				if (espacioRestanteEnSaco - tesoro.arregloCoronas[i].obtenerPeso() < 1 || tesoro.arregloCoronas[i].obtenerPeso() == 0){
					continuar = false;
				}
				else{
					robarCorona(tesoro.arregloCoronas[i]);
					continuar = false;
				}
			}
			i++;
		}
		break;

	case 'A':
		while (continuar){
			if (tesoro.arregloAnillos[i].obtenerValorReal() == tesoro.tesoroOrdenado[punteroDeTesoroOrdenado].second){
				if (espacioRestanteEnSaco - tesoro.arregloAnillos[i].obtenerPeso() < 1 || tesoro.arregloAnillos[i].obtenerPeso() == 0){
					continuar = false;
				}
				else{
					robarAnillo(tesoro.arregloAnillos[i]);
					continuar = false;
				}
			}
			i++;
		}
		break;

	default:
		break;

	}

	return continuar;
}

void Pirata::robarRecursivo(Tesoro tesoro, int punteroDeTesoroOrdenado){
	ejecutandoseRecursivo = true;

	if (espacioRestanteEnSaco > 0 && (tesoro.tesoroOrdenado[punteroDeTesoroOrdenado].first == 'M' || tesoro.tesoroOrdenado[punteroDeTesoroOrdenado].first == 'L'
		|| tesoro.tesoroOrdenado[punteroDeTesoroOrdenado].first == 'R' || tesoro.tesoroOrdenado[punteroDeTesoroOrdenado].first == 'A')) {
		
		robar(tesoro, punteroDeTesoroOrdenado);
		punteroDeTesoroOrdenado++;

		robarRecursivo(tesoro, punteroDeTesoroOrdenado);
	}

}

void Pirata::imprimirEstadoFinal(){
	ofstream archivoBotin;

	if (ejecutandoseRecursivo){
		archivoBotin.open("robado-recursivo.txt", ofstream::app);
	}
	else{
		archivoBotin.open("robado-no-recursivo.txt", ofstream::app);
	}

	archivoBotin << "Peso total del botin: " << pesoDelBotin << ", Valor total del botin: " << valorDelBotin << ", Especio libre en saco:" << espacioRestanteEnSaco << endl;
	archivoBotin.close();
}

void Pirata::reiniciarValores(){
	ejecutandoseRecursivo = false;
	espacioRestanteEnSaco = tamanoDelSaco;
	valorDelBotin = 0;
	pesoDelBotin = 0;
}

//roba en forma optima tomando en cuenta el peso que puede cargar y el valor en relacion al peso de cada objeto
void Pirata::robarNoRecursivo(Tesoro tesoro, int punteroDeTesoroOrdenado){

	while ( espacioRestanteEnSaco > 0 && (tesoro.tesoroOrdenado[punteroDeTesoroOrdenado].first == 'M' || tesoro.tesoroOrdenado[punteroDeTesoroOrdenado].first == 'L'
			|| tesoro.tesoroOrdenado[punteroDeTesoroOrdenado].first == 'R' || tesoro.tesoroOrdenado[punteroDeTesoroOrdenado].first == 'A')) {

		robar(tesoro, punteroDeTesoroOrdenado);
		punteroDeTesoroOrdenado++;
	}
}