
 /*DESARROLLAR UN PROGRAMA EN C EL CUAL, EN LA MATERIA DE PROGRAMACION N ALUMNOS
	PRESENTAN CINCO EXAMENES PARCIALES Y SE DESEA OBRENER:
	A). EL PROMEDIO DE CADA ALUMNO. (imprimir matricula, nombre y promedio)
	B). ALUMNOS CUYA CALIFICACION EN EL TERCER EXAMEN  SEA
		 MAYOR A 95. (imprimir matricula, nombre y promedio)
	C). EL PROMEDIO GENERAL DEL CUARTO PARCIAL.
	D). REPORTE DE LOS PROMEDIOS ORDENADO DESCENDENTEMENTE. (imprimir matricula, nombre y promedio)
	LA INFORMACION DE CADA ALUMNO ES MATRICULA, NOMBRE Y APELLIDO, Y LOS
	RESULTADOS DE LOS CINCO EXAMENES PARCIALES                              */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct alumno
{
  long int mat;
  char nom[30];
  float cal[5];
  float prom;
};

int captura_datos(struct alumno *pp);
void reporte_alumnos(int i, struct alumno *pp);
void nueve_tercer_parcial(int i, struct alumno *pp);
void promediogen_cuartop(int i, struct alumno *pp);
void mayor_menor(int i, struct alumno *pp);


int main()
{
  struct alumno al[' '];
  int n, opc;
  do
    {
    	do
    	  {
    	  	system("cls");
			printf("\n\n\t\t\t\t Menu Principal\n\n");
			printf("\n\t\t 1) Captura de Datos");
			printf("\n\t\t 2) Promedio de cada estudiante");
			printf("\n\t\t 3) Calificacion mayor que 90 tercer parcial");
			printf("\n\t\t 4) Promedio general de cuarto examen parcial");
			printf("\n\t\t 5) Reporte ordenado por promedio descendente");
			printf("\n\t\t 6) Salir\n\n\n\t Opcion > ");
			scanf("%d", &opc);
		  }while(opc < 1 || opc > 6);
		  
		switch(opc)
		 {
  			case 1:	n=captura_datos(&al[0]);
  					printf("\n\n");
  					system("pause");
  					break;
  			case 2:	reporte_alumnos(n,&al[0]);
  					printf("\n\n");
  					system("pause");
  					break;
  			case 3:	nueve_tercer_parcial(n, &al[0]);
  					printf("\n\n");
  					system("pause");
  					break;
  			case 4:	promediogen_cuartop(n, &al[0]);
  					printf("\n\n");
  					system("pause");
  					break;
  			case 5:	mayor_menor(n, &al[0]);
  					printf("\n\n");
  					system("pause");
  					break;
  			case 6: printf("\n\n\t Salida del Sistema");
  		 }
	}while(opc != 6);
	
	printf("\n\n\n\t\t\t FIN DEL PROGRAMA");
	printf("\n\n\n");
	system("pause");
	return 0;
}

int captura_datos(struct alumno *pp)
{
		char aux[' '];
		int j, op1, op, i=0;
	
	system("cls");
	          do  
				 {
				 	
				 	system("cls");
					do
					 {
					   do
					    {
						   printf("\nMatricula: ");
						   fflush(stdin);
       				 	   gets(aux);
       					   pp->mat=atoi(aux);
					    } while(pp->mat < 1);

					   fflush(stdin);
					   printf("\nNombre y apellido: ");
					   gets(pp->nom);

					   for(j=0;j<5;j++)
					    {
						   do
						     {
						        printf("\nCalificacion %d del alumno %d: ",j+1,i+1);
						      	fflush(stdin);
						      	gets(aux);
						      	pp->cal[j]=atof(aux);
						     }while(pp->cal[j] < 0 || pp->cal[j] > 100);
						   
					    }
					    
					    do
					     {
					     	printf("\nEs correcta la informacion 1-SI 2-NO\nOpcion: ");
					     	scanf("%d",&op1);
					     }while(op1 != 1 && op1 != 2);
				     }while(op1==2);

					do
					 {
						 printf("\nDeseas ingresar otro alumno? 1-SI 2-NO\nOpcion: ");
						scanf("%d",&op);
					 } while(op != 1 && op != 2);

					i++;
					pp++;
				 } while(op == 1);  // cierre del ciclo
		return i;
}

void reporte_alumnos(int i, struct alumno *pp)
{
	int j, k;
	float suma;
	
	printf("\nALUMNOS Y SUS CALIFICACIONES");
	system("cls");
	for(j=0;j<i;j++)
				 {
				 	printf("\n\n\n\t Nombre: %s", pp->nom);
					printf("\n\t Matricula: %d", pp->mat);
					suma=0.0;
					for(k=0;k<5;k++)
						suma = suma + pp->cal[k];
					pp->prom = suma / 5;
					printf("\n\t Promedio: %.2f", pp->prom); 
					
					pp++;
				 }
				
}

void nueve_tercer_parcial(int i, struct alumno *pp)
{
	 int j;
		printf("\nAlUMNOS CON CALIFICACION MAYOR A 9 EN EL TERCER PARCIAL");
		system("cls");
			for(j=0;j<i;j++)
			  {
				if(pp->cal[2]>95)
				  printf("\n\n\n\t Nombre del alumno: %s\n\t Matricula del alumno: %d\n\t Calificacion: %.2f",pp->nom, pp->mat, pp->cal[2]);
				pp++;
			  }
}

void promediogen_cuartop(int i, struct alumno *pp)
{
	int j;
	float suma = 0.0, promgen=0.0;
			printf("\nPROMEDIO GENERAL DE ALUMNOS EN EL CUARTO PARCIAL: ");
			
			system("cls");
				for(j=0;j<i;j++)
				  {
					suma = suma + pp->cal[3];
					promgen=(float)(suma/i);
					pp++;
				  }	
				
				printf("\n\n\n\tPromedio general del cuarto examen: %.2f",promgen);
			
			
}

void mayor_menor(int i, struct alumno *pp)
{
	struct alumno aux;
	struct alumno *cal=pp, *paux=pp;
		int j, m, k;
		system("cls");
		printf("\n\n\n\t REPORTE ALUMNOS ORDENADO DE  MAYOR A MENOR PROMEDIO: ");
		
		
				for(j=0;j<i;j++)
				  {
				    float suma=0.0;
						for(k=0;k<5;k++)
						  suma = suma + pp->cal[k];
						pp->prom = suma / 5;
						pp++;
				  }
		 pp=paux;
		 for(j=0;j<i-1;j++)
		  {	
			cal=pp;
			for(m=j;m<i;m++)
			  {
				if( pp->prom < cal->prom)
				  {
					aux=*pp;
					*pp=*cal;
					*cal=aux;
				  }
				cal++;
			  }
			pp++;
		 }
		
		pp=paux;
		
		for(j=0;j<i;j++)
		 {
			printf("\n\n\n\n\t Nombre del alumno: %s\n\t Matricula: %d\n\t Promedio: %.2f", pp->nom, pp->mat, pp->prom);
			pp++;
		 }
}

