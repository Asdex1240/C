#include<stdlib.h>
#include<stdio.h>
void operacion(int n);
int ingresa();
int main(){
    int n;
    n = ingresa();
    operacion(n);
    return 0;
}
void operacion(int n){
    n = n+5;
    printf("El resultado es : %d\n",n);
}
int ingresa(){
    int n;
    printf("Ingresa un numero: ");
    scanf("%d",&n);
    return n;
}