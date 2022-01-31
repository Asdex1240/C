#include<stdio.h>
#include<stdlib.h>

int main(){
    int tabla[5][5];
    int i, acum, op;
    acum = 0;
    //Datos
    tabla[0][0] = 1762;
    tabla[0][1] = 987;
    tabla[0][2] = 176;
    tabla[0][3] = 2654;
    tabla[0][4] = 287;
    tabla[1][0] = 1000;
    tabla[1][1] = 342;
    tabla[1][2] = 543;
    tabla[1][3] = 996;
    tabla[1][4] = 342;
    tabla[2][0] = 754;
    tabla[2][1] = 908;
    tabla[2][2] = 276;
    tabla[2][3] = 875;
    tabla[2][4] = 276;
    tabla[3][0] = 874;
    tabla[3][1] = 765;
    tabla[3][2] = 390;
    tabla[3][3] = 436;
    tabla[3][4] = 150;
    tabla[4][0] = 165;
    tabla[4][1] = 43;
    tabla[4][2] = 25;
    tabla[4][3] = 579;
    tabla[4][4] = 15;
    //Fin datos
    //Menu
    do{
        printf("Hola mundo");
        scanf("%d",&op);
    }while(op < 0 || op > 4);
    //a cantidad de simpatizantes por partido
    switch(op){
        case 1:

                for(i=0; i<5; i++){
                    acum = acum + tabla[i][0];
                }
                printf("Cantidad de simpatizantes: %d",acum);
        break;


    }
    for(i=0; i<5; i++){
        acum = acum + tabla[i][0];
    }
    printf("Cantidad de simpatizantes: %d",acum);
    system("PAUSE");
    return 0;
}