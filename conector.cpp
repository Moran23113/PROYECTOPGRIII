#include "conector.h"
#include <sqlite3.h>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
using namespace std;

void conector::ver(const char* instruccionSQL) {
 sqlite3* db;
    int rc = sqlite3_open("inventario.db", &db);

    char** resultados;
    int numFilas, numColumnas;

    rc = sqlite3_get_table(db, instruccionSQL, &resultados, &numFilas, &numColumnas,NULL);

    for (int i = 0; i < 4; i++) {
        cout << resultados[i]<<"  ";
    }
    cout << endl;

for (int fila = 1; fila <= numFilas; fila++) {
    for (int col = 0; col <4 ; col++) {
        cout << (resultados[fila * numColumnas + col] ? resultados[fila * numColumnas + col] : "NULL") << "\t";
    }
    cout << endl;


    sqlite3_close(db);
}
}

int conector::guardar(const char* instruccionSQL,int fila) {
 sqlite3* db;
    int rc = sqlite3_open("inventario.db", &db);

    char** resultados;
    int numFilas, numColumnas;

    rc = sqlite3_get_table(db, instruccionSQL, &resultados, &numFilas, &numColumnas,NULL);





  
      int resul= atoi(resultados[fila * numColumnas + 2] );
    
    cout << endl;
return resul;

    sqlite3_close(db);
}

string conector::guardar2(const char* instruccionSQL,int fila) {
 sqlite3* db;
    int rc = sqlite3_open("inventario.db", &db);

    char** resultados;
    int numFilas, numColumnas;

    rc = sqlite3_get_table(db, instruccionSQL, &resultados, &numFilas, &numColumnas,NULL);





  
       stringstream ss;
    ss << resultados[fila * numColumnas + 1];
    string resul = ss.str();
    
    cout << endl;
return resul;

    sqlite3_close(db);
}

string conector::guardar3(const char* instruccionSQL,int fila) {
 sqlite3* db;
    int rc = sqlite3_open("inventario.db", &db);

    char** resultados;
    int numFilas, numColumnas;

    rc = sqlite3_get_table(db, instruccionSQL, &resultados, &numFilas, &numColumnas,NULL);





  
       stringstream ss;
    ss << resultados[fila * numColumnas + 4];
    string resul = ss.str();
    
    cout << endl;
return resul;

    sqlite3_close(db);
}
