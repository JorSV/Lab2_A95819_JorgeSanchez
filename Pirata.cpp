/* Main.cpp Laboratorio 2
 * Author: Jorge Sanchez Vargas A95819 */

#include "Pirata.h"
#include <iostream>
#include <fstream>

Pirata::Pirata(){
	//srand (time(0));
	tamanoDelSaco = rand() % rangoDeSaco.first + (rangoDeSaco.second-rangoDeSaco.first);
	valorDelBotin = 0;
	pesoDelBotin = 0;
	ofstream archivoBotin("robado-no-recursivo.txt");
}

Pirata::~Pirata(){
}

void Pirata::robarMoneda(Moneda monedaRobada){
	ofstream archivoBotin;
	archivoBotin.open("robado-no-recursivo.txt", ofstream::app);
	archivoBotin << "Moneda Robada: " << monedaRobada.obtenerID() << ", Valor: " << monedaRobada.obtenerValor() << ", Peso:" << monedaRobada.obtenerPeso() << endl;
	archivoBotin.close();
	valorDelBotin = valorDelBotin+monedaRobada.obtenerValor();
	pesoDelBotin = pesoDelBotin+monedaRobada.obtenerPeso();
	tamanoDelSaco = tamanoDelSaco - monedaRobada.obtenerPeso();
}

void Pirata::robarCollar(Collar collarRobado){
	ofstream archivoBotin;
	archivoBotin.open("robado-no-recursivo.txt", ofstream::app);
	archivoBotin << "Collar Robado: " << collarRobado.obtenerID() << ", Valor: " << collarRobado.obtenerValor() << ", Peso:" << collarRobado.obtenerPeso() << endl;
	archivoBotin.close();
	valorDelBotin = valorDelBotin+collarRobado.obtenerValor();
	pesoDelBotin = pesoDelBotin+collarRobado.obtenerPeso();
	tamanoDelSaco = tamanoDelSaco - collarRobado.obtenerPeso();
}

void Pirata::robarCorona(Corona coronaRobada){
	ofstream archivoBotin;
	archivoBotin.open("robado-no-recursivo.txt", ofstream::app);
	archivoBotin << "Corona Robada: " << coronaRobada.obtenerID() << ", Valor: " << coronaRobada.obtenerValor() << ", Peso:" << coronaRobada.obtenerPeso() << endl;
	archivoBotin.close();
	valorDelBotin = valorDelBotin+coronaRobada.obtenerValor();
	pesoDelBotin = pesoDelBotin+coronaRobada.obtenerPeso();
	tamanoDelSaco = tamanoDelSaco - coronaRobada.obtenerPeso();
}

void Pirata::robarAnillo(Anillo anilloRobado){
	ofstream archivoBotin;
	archivoBotin.open("robado-no-recursivo.txt", ofstream::app);
	archivoBotin << "Anillo Robado: " << anilloRobado.obtenerID() << ", Valor: " << anilloRobado.obtenerValor() << ", Peso:" << anilloRobado.obtenerPeso() << endl;
	archivoBotin.close();
	valorDelBotin = valorDelBotin+anilloRobado.obtenerValor();
	pesoDelBotin = pesoDelBotin+anilloRobado.obtenerPeso();
	tamanoDelSaco = tamanoDelSaco - anilloRobado.obtenerPeso();
}

//roba en forma optima tomando en cuenta el peso que puede cargar y el valor en relacion al peso de cada objeto
void Pirata::Robar(Moneda arrMonedas[], Collar arrCollares[], Corona arrCoronas[], Anillo arrAnillos[],
										pair<char,double> ordenValorPeso[], int punteroDeTesoroOrdenado){

	char tipoDeTesoroApuntado = 0;
	while ( tamanoDelSaco > 0 && (ordenValorPeso[punteroDeTesoroOrdenado].first == 'M' || ordenValorPeso[punteroDeTesoroOrdenado].first == 'L'
			|| ordenValorPeso[punteroDeTesoroOrdenado].first == 'R' || ordenValorPeso[punteroDeTesoroOrdenado].first == 'A')) {

		tipoDeTesoroApuntado = ordenValorPeso[punteroDeTesoroOrdenado].first;
		bool continuar = true;
		int i=0;

		switch(tipoDeTesoroApuntado){
			case 'M':
				while (continuar){
					if (arrMonedas[i].obtenerValorReal() == ordenValorPeso[punteroDeTesoroOrdenado].second){
						if(tamanoDelSaco-arrMonedas[i].obtenerPeso() < 1 || arrMonedas[i].obtenerPeso()==0 ){
							continuar = false;
						}else{
						robarMoneda(arrMonedas[i]);
						continuar = false;
						}
					}
					i++;
				}
				break;

			case 'L':
				while (continuar){
					if (arrCollares[i].obtenerValorReal() == ordenValorPeso[punteroDeTesoroOrdenado].second){
						if(tamanoDelSaco-arrCollares[i].obtenerPeso() < 1 || arrCollares[i].obtenerPeso()==0){
							continuar = false;
						}else{
						robarCollar(arrCollares[i]);
						continuar = false;
						}
					}
					i++;
				}
				break;

			case 'R':
				while (continuar){
					if (arrCoronas[i].obtenerValorReal() == ordenValorPeso[punteroDeTesoroOrdenado].second){
						if(tamanoDelSaco-arrCoronas[i].obtenerPeso() < 1 || arrCoronas[i].obtenerPeso()==0){
							continuar = false;
						}else{
						robarCorona(arrCoronas[i]);
						continuar = false;
						}
					}
					i++;
				}
				break;

				case 'A':
					while (continuar){
						if (arrAnillos[i].obtenerValorReal() == ordenValorPeso[punteroDeTesoroOrdenado].second){
							if(tamanoDelSaco-arrAnillos[i].obtenerPeso() < 1 || arrAnillos[i].obtenerPeso()==0){
								continuar = false;
							}else{
							robarAnillo(arrAnillos[i]);
							continuar = false;
							}
						}
						i++;
					}
					break;

			default:
				break;

		}

		punteroDeTesoroOrdenado++;
	}

	ofstream archivoBotin;
	archivoBotin.open("robado-no-recursivo.txt", ofstream::app);
	archivoBotin << "Peso total del botin: " << pesoDelBotin << ", Valor total del botin: " << valorDelBotin << ", Especio libre en saco:" << tamanoDelSaco << endl;
	archivoBotin.close();
}
