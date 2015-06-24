/* Anillo.h Laboratorio 2
 * Author: Jorge Sanchez Vargas A95819 */

#ifndef ANILLO_H_
#define ANILLO_H_

using namespace std;

class Anillo{

	private:
		int valor;
		int peso;
		Anillo* idUnico;
		double valorReal;
		bool estaEnElBotin;

	public:
		void asignarValor(int);
		void asignarPeso(int);
		void calcularValorReal();
		void meterAlBotin();

		int obtenerValor();
		int obtenerPeso();
		Anillo* obtenerID();
		double obtenerValorReal();
		bool estaEnBotin();

		Anillo();
		Anillo(int, int);
		~Anillo();

};

#endif /* ANILLO_H_ */
