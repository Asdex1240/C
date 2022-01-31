#include<stdio.h>
//El struct es una coleccion de datos :D
typedef struct Complejo
{
    float re;
    float im;
}Complejo;

void imprimir(Complejo complejo);

int main(){
    Complejo c1 = {1,10};
    Complejo c2 = {2,-17};
    imprimir(c2);
    getch();
    return 0;
}

void imprimir(Complejo complejo){
    printf("%.4f + %.4f", complejo.re, complejo.im);
}