#include <iostream>
#include <cstdlib>
#include <math.h>
/*	NOMBRE: SERGIO YAEL GARZA FLORES.
	FECHA: 29 DE OCTUBRE DEL 2021.
	DESCRIPCION: VALIDACIONES CON CICLOS.*/
using namespace std;
int main(int argc, char** argv) {
int distancia, opcion, n1, tabla;
float x1, x2, y1, y2, respuesta,base, resultado, altura; 
	
	cout<<"Selecciona la operacion que deseas realizar."<<endl;
	cout<<"1 <- El area de un triangulo en centimetros."<<endl;
	cout<<"2 <- La distancia que hay entre dos puntos o coordenas."<<endl;
	cout<<"3 <- La tabla de multiplicar de un numero."<<endl;
	cout<<"Opcion: ";
	cin>>opcion;
	if (opcion >=0 && opcion <=3)
	switch (opcion)
		case 1: 
		{
			cout<<"*** Has seleccionado: El area de un triangulo en centimetros ***"<<endl;
			cout<<"Ingresa la base del triangulo en cm: ";
			cin>>base;
			if (base >0)
			{
				cout<<"Ingresa la altura del triangulo en cm: ";
				cin>>altura;
				if (altura >0)
				{
					resultado=(base*altura)/2; 
					cout<<"El area de tu triangulo es: "<<resultado<<" centimetros cuadrados."<<endl;
				}
				else
				{
					cout<<"Lo siento, la altura debe de ser positiva."<<endl;
				}
			}
			else
			{
				cout<<"Lo siento, la base debe de ser positiva."<<endl;
			}
			break;
		case 2:
		{
			cout<<"*** Has seleccionado: la distancia que existe entre dos coordenadas. ***"<<endl;
			cout<<"Ingrese la coordenada x1: ";
			cin>>x1;
			cout<<"Ingresa la coordenada y1: ";
			cin>>y1;
			cout<<"Ingresa la coordenada x2: ";
			cin>>x2;
			cout<<"Ingresa la coordenada y2: ";
			cin>>y2;
			distancia=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
			cout<<"Dadas las coordenadas la distancia es igual a: "<<distancia<<endl;
			break;
		}
		case 3:
		{
			cout<<"*** Has seleccionado: La tabla de multiplicar de un numero. ***"<<endl;
			cout<<"Ingresa el numero al que deseas generar su tabla de multipicar: ";
			cin>>n1;
			if (n1 >0)
			{
				for(int i=0;i<=10;i++)
				{
					tabla = n1*i;
					cout<<n1<<" X "<<i<<" = "<<tabla<<endl;
				}
			}
			else 
			{
				cout<<"Lo siento, ingresa un numero positivo."<<endl;
			}
			break;
		}
	}
	else 
	{
		opcion <=3;
		cout<<"Lo siento, solo puedes ingresar el numero de las opciones del menu."<<endl;
		
	}
	cout<<"Gracias por utilizar el programa."<<endl;
	system("PAUSE");
	return 0;
}
