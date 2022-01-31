#include <stdio.h>
#include <stdlib.h>
/*
int main(){     //Metodo 1

    FILE * flujo = fopen("archivos.c", "rb");  //Abrir archivo y tenerlo en flujo

    if(flujo == NULL){
        perror("Error al abrir el archivo");
        return 1;
    }
    char caracter;

    while(feof(flujo)==0){      //Leer caracter por caracter    feof end of file, al final dará un cero
        caracter = fgetc(flujo);            //Recibe el flujo y lo que hace es regresarme un caracter del archivo
        printf("%c", caracter);
    }
    fclose(flujo);              //Es una buena practica estar cerrando el archivo
    printf("\n\nSe ha leido el archivo correctamente..\n");
    system("PAUSE");
    return 0;
}
*/
/*
int main(){     //Metodo 2                     //De esta manera puedo manipular el archivo

    FILE * flujo = fopen("datos.txt", "rb");  //Abrir archivo y tenerlo en flujo

    if(flujo == NULL){
        perror("Error al abrir el archivo");
        return 1;
    }
    int numero;
    char cadena[10];

    while(feof(flujo)==0){      //Leer caracter por caracter    feof end of file, al final dará un cero
        fscanf(flujo, "%d%s", &numero,&cadena);            //Recibe el flujo y lo que hace es regresarme un caracter del archivo
        numero *=10;
        printf("%d %s\n", numero, cadena);
    }
    fclose(flujo);              //Es una buena practica estar cerrando el archivo
    printf("\n\nSe ha leido el archivo correctamente..\n");
    system("PAUSE");
    return 0;
}
*/
int main(){                                     //Metodo 3
    FILE * flujo = fopen("datos.txt", "rb");
    if(flujo == NULL){
        perror("Error en la apertura del archivo");
        return 1;
    }
    fseek(flujo, 0, SEEK_END);          //Recibir cuantos espacios va a mover, seek end, desde donde va a empezar a mover
    int num_elementos = ftell(flujo);   //Esto sirve para preguntar donde se encuentra el flujo de datos
    rewind(flujo);                      //Mover al incio del archivo

    char * cadena = (char *) calloc(sizeof(char), num_elementos);   //Asignar espacio en memoria
    if(cadena == NULL){                                             //PReguntar si la cadena esta vacia
        perror("Error en la reserva de memoria");
        return 2;
    }
    int num_elementos_leidos = fread(cadena, sizeof(char), num_elementos, flujo);   //Fread lo que hace es meter el contenido del flujo, tamaño, que quiero leer.
    if(num_elementos_leidos != num_elementos){      //Comprobar la cantidad de numero leidos es diferente de la cantidad de la que tivo que leer
        perror("Error leyendo el archivo");
        return 3;
    }
    printf("%s", cadena);
    free(cadena);       //Liberar memoria
    fclose(flujo);      //Cerrar el archivo
    printf("\n\nSe ha leido correctamente el archivo");
    system("PAUSE");
    return 0;
}