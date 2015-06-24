/* Collar.h Laboratorio 2
 * Author: Jorge Sanchez Vargas A95819 */

#ifndef COLLAR_H_
#define COLLAR_H_

using namespace std;

class Collar{

	private:
		int valor;
		int peso;
		Collar* idUnico;
		double valorReal;
		bool estaEnElBotin;

	public:
		void asignarValor(int);
		void asignarPeso(int);
		void calcularValorReal();
		void meterAlBotin();

		int obtenerValor();
		int obtenerPeso();
		Collar* obtenerID();
		double obtenerValorReal();
		bool estaEnBotin();

		Collar();
		Collar(int, int);
		~Collar();

};

#endif /* COLLAR_H_ */
