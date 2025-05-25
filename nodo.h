#ifndef NODO_H
#define NODO_H
using namespace std;
#include <iostream>
class nodo
{
	public:
		nodo *sig;
		int id;
		string farmaco;
		int cantidad;
		double precio;
		string prioridad;
		int multi;
	protected:
};

#endif
