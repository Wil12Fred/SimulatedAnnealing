#include <set>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#include "xorshift.h" //semilla y función para puntos aleatorios
#include "matematica.h" //definiciones basicas
#include "genetico.h"
#include "simulated_annealing.h"

int main(int argc, char **argv){
	SeedXorShift();
	//Algoritmo genetico
	/*Practica2<Individuo> P2g(200,300,18);
	Genetico<Practica2<Individuo> > G(&P2g,0.3,0.2,false);
	Individuo mejorg=G.iniciar(false);*/

	//Algoritmo genetico con eletismo
	/*Practica2<Individuo> P2g(200,300,18);
	Genetico<Practica2<Individuo> > G(&P2g,0.3,0.2,true);
	Individuo mejorg=G.iniciar(false);*/

	//Simulated annealing
	Practica2<Individuo> P3(1,300,18);
	Simulated_Annealing<Practica2<Individuo> > SA(&P3);
	Individuo mejor=SA.iniciar(false);
	pair<double,double> X=mejor.representacion.getX();
	return 0;
}
