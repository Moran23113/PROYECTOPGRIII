#include <iostream>
#include "conector.h"
#include "nodo.h"
#include <ctime>
#include <cstdlib>
using namespace std;
conector metodo;
int opc;
int num=0;
int confirm=NULL;
nodo *I,*T,*F;
void multi();
void agregar(int id,int cantidad);
void ver();
void ver2();
void ver3();
string prioridad;
int suma();
void prioridad1();
const char* instruccionSQL = "SELECT * FROM medicamentos";
	int id;
string nombre;
string direccion;
int cantidad;
void facturar(string direccion,string nombre);

int main(int argc, char** argv) {
	
	do{
		cout<<"Bienvenido"<<endl;
		cout<<"Seleccione una opcion"<<endl;
		cout<<"1)Ver Productos"<<endl;
		cout<<"2)Agregar al carrito"<<endl;
		cout<<"3)Ver Carrito"<<endl;
		cout<<"4)Facturar"<<endl;
		cout<<"5)Revisar Estado del Producto"<<endl;
		cout<<"0)Salir"<<endl;
		cin>>opc;
		switch(opc){
			
			case 1:

				
metodo.ver(instruccionSQL);

break;

	case 2:
		cout<<"Ingrese el numero del farmaco"<<endl;
		cin>>id;
		cout<<"Ingrese la cantidad del farmaco"<<endl;
		cin>>cantidad;
		if(id>20){
			cout<<"Farmaco no encontrado"<<endl;
		}
		else{
			
		
	agregar(id,cantidad);	
}
	break;
	
	case 3:
		ver();
	
	break;
	
	case 4:
		
	cout<<"Ingrese su nombre"<<endl;
	cin>>nombre;
	cout<<"Ingrese su direccion"<<endl;
	cin>>direccion;	
	facturar(direccion,nombre);
	
break;

case 5:
if(confirm==NULL){
cout<<"Sin productos en espera"<<endl;
}
else{
prioridad1();
	

}
break;

case 0:
	break;
	
	
	default:
		cout<<"Opcion No Valida"<<endl;
	
}
	}while(opc!=0);
	

	return 0;
}


void agregar(int id,int cantidad){
string farmaco;
double precio;
	T=new nodo();

	T->id=id;
	T->cantidad=cantidad;
	
T->farmaco=metodo.guardar2(instruccionSQL,id);
T->precio=metodo.guardar(instruccionSQL,id);
T->prioridad=metodo.guardar3(instruccionSQL,id);

if(I==NULL){
	I=T;
	F=T;
	
}
else{
	F->sig=T;
	F=T;
}

}

//-------------------------------------
//-------------------------------------
//-------------------------------------

void ver(){
	T=I;
	int num=1;

if(T!=NULL){
cout<<"Carrito"<<endl;
	while(T!=NULL){
	
		
		
		cout<<""<<endl;
		cout<<"#"<<num<<endl;
		cout<<""<<endl;
		cout<<"Farmaco: "<<T->farmaco<<endl;
		cout<<"Cantidad: "<<T->cantidad<<endl;
		cout<<"Precio: "<<T->precio<<endl;
			cout<<""<<endl;
		num++;
		T=T->sig;
	
}
}

else{
	cout<<"Carrito Vacio"<<endl;
}
}
//-------------------------------------
//-------------------------------------
//-------------------------------------

void ver3(){
	T=I;
	int num=1;

	while(T!=NULL){		
	    cout<<T->farmaco<<"          "<<T->cantidad<<"                             "<<T->precio<<" LPS"<<endl;
		
		num++;
		T=T->sig;
	
}
}


//-------------------------------------
//-------------------------------------
//-------------------------------------

void multi(){
T=I;
while(T!=NULL){

T->multi = (T->cantidad) * (T->precio);
T=T->sig;
	
}
}

//-------------------------------------
//-------------------------------------
//-------------------------------------


void ver2(){
	T=I;
	while(T!=NULL){
		
		cout<<T->multi<<endl;
		T=T->sig;
	}
}

//-------------------------------------
//-------------------------------------
//-------------------------------------

int suma(){
	
	T=I;
	int suma=0;
	while(T!=NULL){
	
	suma=suma + T->multi;

	T=T->sig;
		
	}
	return suma;

}
//-------------------------------------
//-------------------------------------
//-------------------------------------
	

void facturar(string direccion,string nombre){
	time_t tiempoActual = time(0);
	 tm* tiempoLocal = localtime(&tiempoActual);
  srand(time(0));
  int numeroAleatorio;
   int numeroAleatorio2;
    int numeroAleatorio3;
     int numeroAleatorio4;
      int numeroAleatorio5;
   int rangoInicial = 100;
    int rangoFinal = 999;
    
      for (int i = 0; i < 5; i++) {
         numeroAleatorio= rand() % (rangoFinal - rangoInicial + 1) + rangoInicial;
         numeroAleatorio2= rand() % (rangoFinal - rangoInicial + 1) + rangoInicial;
         numeroAleatorio3= rand() % (rangoFinal - rangoInicial + 1) + rangoInicial;
         numeroAleatorio4= rand() % (rangoFinal - rangoInicial + 1) + rangoInicial;
         numeroAleatorio5= rand() % (rangoFinal - rangoInicial + 1) + rangoInicial;
    }
char x;
	multi();

	
	
	cout<<"Medientregas"<<endl;	
	cout<<"San Pedro Sula"<<endl;
	cout<<"Fecha"<<endl;
    cout << tiempoLocal->tm_year + 1900 << '-'  
         << tiempoLocal->tm_mon + 1 << '-'      
         << tiempoLocal->tm_mday << ' '         
         << tiempoLocal->tm_hour << ':'         
         << tiempoLocal->tm_min << ':'           
         << tiempoLocal->tm_sec << endl;   
	cout<<"No. de Factura "<<numeroAleatorio<<"-"<<numeroAleatorio2<<"-"<<numeroAleatorio3<<numeroAleatorio4<<numeroAleatorio5<<endl;
	cout<<""<<endl;
	cout<<"Cliente: "<<nombre<<endl;
	cout<<"Direccion del Cliente :"<<direccion<<endl;
	
	cout<<"D E S C R I P C I O N"<<endl;
	cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
	cout<<"Farmaco "<<"                 "<<"Cantidad "<<"                      "<<"  Precio"<<endl;
	cout<<""<<endl;
	ver3();
	
	cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
	cout<<"Subtotal: "<<" LPS"<<suma()<<endl;	
	cout<<"ISV 15%: "<<" LPS"<<suma()*0.15<<endl;
	cout<<"Delivery: Gratuito-->La Casa Invita :)"<<endl;
	int todo=suma()*0.15;
	cout<<" "<<endl;
	cout<<"TOTAL A PAGAR: "<<suma()+todo<<" LPS"<<endl;
	cout<<" "<<endl;
	cout<<"Metodo de pago: E/T"<<endl;
	char x3;
	cin>>x3;
		switch(x3){
		case 'E':
			cout<<"El Repartidor estara al tanto de recoger su dinero!"<<endl;
			break;
			
			case 'T':
					cout<<"Ingrese su numero de Tarjeta de Pago"<<endl;
					int code;
					cin>>code;
					cout<<"Ingrese la fecha de caducidad"<<endl;
					string fecha;
					cin>>fecha;
					cout<<"Ingrese los numeros de seguridad"<<endl;
					int code2;
					cin>>code2;
				
	}
	cout<<"Confirmar Compra? S/N:"<<endl;
	char x2;
	cin>>x2;
	switch(x2){
		case 'S':
			cout<<"Compra en curso..."<<endl;
			cout<<"."<<endl;
			cout<<"."<<endl;
			cout<<"."<<endl;
			cout<<"."<<endl;
			cout<<"Compra realizada con exito"<<endl;
			cout<<"Favor revisar el estado de su producto"<<endl;
			cout<<""<<endl;
			confirm=1;
			break;
			
			case 'N':
				cout<<"Compra cancelada"<<endl;
				cout<<""<<endl;
				break;
				
				
	}


}

//-------------------------------------
//-------------------------------------
//-------------------------------------

/*
void revisar(){
		
		if(num==3){
	cout<<"Producto en camino..."<<endl;
	cout<<"Gracias por su paciencia..."<<endl;
	}
	else{
	

	cout<<"Producto en tienda..."<<endl;
	cout<<"Gracias por su paciencia..."<<endl;

}
num++;

	

}
*/

void prioridad1(){
	T=I;
	int n=0;
	bool e=false;
	
	while(T!=NULL and !e){
		
	
	
	if(T->prioridad=="Alta"){
		e=true;
		n=1;
		
	}
	else{
		T=T->sig;
	}
}
		
	if(n==1){	
	cout<<"Producto prioritario detectado,su producto esta camino..."<<endl;	
	}
	else if (n==0){
	cout<<"Su producto llegara con un tiempo cotidiano"<<endl;		
	}	

	

	

}
