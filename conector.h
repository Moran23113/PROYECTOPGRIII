#ifndef CONECTOR_H
#define CONECTOR_H
#include <iostream>
using namespace std;
class conector
{
	public:
		
		void ver(const char* instruccionSQL) ;
	int guardar(const char* instruccionSQL,int fila);
	string guardar2(const char* instruccionSQL,int fila);
	string guardar3(const char* instruccionSQL,int fila);
	protected:
};

#endif
