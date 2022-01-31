#include<stdlib.h>
#include<stdio.h>
#include<math.h>
//menus
void menu();
void menuBasicas();
void menuEc();
//Fin menus

//Funciones
void basicas();
    void opBasicas(int op);
    float suma(float n1, float n2);
    float resta(float n1, float n2);
    float mult(float n1, float n2);
    float divi(float n1, float n2);
void ecuaciones();
    float lin(float x, float ind, float igu);
    float agLin();
    float cuad(float xC, float x, float ind, float igu, int i);
    float agCuad(int i);

//Fin funciones

int main(){
    int op,op1;
    do{
        do{
            menu();
            printf("\t");
            scanf("%d",&op);
        }while(op < 0);
        switch(op){
            case 1: basicas();
            break;

            case 2: ecuaciones();
            break;
        }
        printf("Quieres volver a ejecutar?\n\t[1-Si / 2-No]\n\t");
        scanf("%d",&op1);
    }while(op1==1);

    system("PAUSE");
    return 0;
}
//Menus
void menu(){
    printf("\t Menu de opciones\n");
    printf("\t1 Operaciones Basicas\n\t2 Ecuaciones\n");
}
void menuBasicas(){ 
    printf("\tMenu de opciones\n");
    printf("\t1 Sumas\n\t2 Restas\n\t3 Multiplicacion\n\t4 Division\n"); 
}
void menuEc(){
    printf("\tMenu de opciones\n");
    printf("\t1 Lineales\n\t2 Cuadraticas\n");
}
//Fin menus

//Basicas
void basicas(){
    int op;
    do{
        menuBasicas();
        printf("\t");
        scanf("%d", &op);
    }while(op<0);
    opBasicas(op);
}

void opBasicas(int op){
    float n1, n2, final;
    printf("Ingresa primer numero: ");
    scanf("%f", &n1);
    printf("Ingresa segundo numero: ");
    scanf("%f", &n2);
    switch(op){
        case 1: final = suma(n1, n2);
        break;
        case 2: final = resta(n1,n2);
        break;
        case 3: final = mult(n1, n2);
        break;
        case 4: final = divi(n1, n2);
        break;
    }
    printf("El resultado es: %.2f\n", final);
}
float suma(float n1, float n2){
    float resultado;
    resultado = n1 + n2;
    return resultado;
}
float resta(float n1, float n2){
    float resultado;
    resultado = n1 - n2;    
    return resultado;
}
float mult(float n1, float n2){
    float resultado;
    resultado = n1 * n2;    
    return resultado;
}
float divi(float n1, float n2){
    float resultado;
    if(n2 == 0){
        return 0;
    }else{
        resultado = n1 / n2;    
        return resultado;
    }
}
//Fin Basicas

//Ecuaciones
void ecuaciones(){
    int op, i;
    float resultado;
    do{
        menuEc();
        printf("\t");
        scanf("%d",&op);
    }while(op <0);
    switch(op){
        case 1: 
            resultado = agLin();
            printf("El valor de x = %.2f \n", resultado);
        break;
        case 2:
                resultado = agCuad(i);
                if(resultado == 0){
                    printf("No tiene solucion\n");
                }else{
                    printf("El valor de x = %.2f \n", resultado);
                    printf("El valor de x = %.2f \n", resultado);
                } 
                       
        break;
    }   
}
float agLin(){
    float x, ind, igu, resultado;
    printf("Termino con x: ");
    scanf("%f", &x);
    printf("Termino independiente: ");
    scanf("%f", &ind);
    printf("Termino igualado: ");
    scanf("%f", &igu);
    resultado = lin(x, ind, igu);
    return resultado;
}
float lin(float x, float ind, float igu){
    float operacion;
    operacion = resta(igu, ind);
    operacion = divi(operacion, x);
    return operacion;
}
float 
agCuad(int i){
    float xC, x, ind, igu, resultado;

        printf("Termino cuadratico: ");
        scanf("%f", &xC);
        printf("Termino lineal: ");
        scanf("%f", &x);
        printf("Termino independiente: ");
        scanf("%f", &ind);
        printf("Termino igualado: ");
        scanf("%f", &igu);
        resultado = cuad(xC, x, ind, igu, i);

    return resultado;
}
float cuad(float xC, float x, float ind, float igu, int i){
    float c, b, ac, dis, raiz, resultado;
    c = resta(ind, igu);
    b = mult(x, x); //b = b al cuadrado
    ac = mult(xC, c) * 4;       //
    dis = resta(b, ac);
    if(dis>0){
        raiz = (sqrt(dis));
            resultado = suma(-x, raiz) / 2*xC;  
    }else{
        return 0;
    }
    return resultado;
}