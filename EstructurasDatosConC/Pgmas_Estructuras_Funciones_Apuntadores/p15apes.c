/*DESARROLLAR UN PROGRAMA EN C EL CUAL, EN LA MATERIA DE PROGRAMACION N ALUMNOS
	PRESENTAN CINCO EXAMENES PARCIALES Y SE DESEA OBRENER:
	A). LA MATRICULA Y EL PROMEDIO DE CADA ALUMNO.
	B). LAS MATRICULAS DE LOS ALUMNOS CUYA CALIFICACION EN EL TERCER EXAMEN  SEA
		 MAYOR A 95.
	C). EL PROMEDIO GENERAL DEL CUARTO PARCIAL.
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
struct alumno al[' '];
struct alumno *pp;
struct alumno aux;
//struct alumno *cal=pp, *paux=pp;
struct alumno *cal;
char aux1[' '];
int j,k, m, op1, op, i=0;
float suma=0.0, suma1 = 0.0, promgen=0.0;

int main()
{
  do
    {
      //int op, n, opc;
      system("cls");
      printf("\n\n\n\t\t\t M E N U\n\t 1.- Captura de datos\n\t 2.- Matricula y promedio de alumnos\n\t 3.- Reporte calificacion mayor a 9 3 parcial\n\t 4.- Reporte de promedio general 4 parcial\n\t 5.- Reporte alumnos de mayor a menor promedio\n\t 6.- Salir\nOpcion: ");
      do
       {
         printf("\n Que opcion desea [1-6]: ");
	     scanf("%d",&op);
       }while(op != 1 && op != 2 && op != 3 && op != 4 && op != 5 && op != 6);

      switch(op)
       {
  	     case 1: pp=&al[0];
	  		     system("cls");
	             do  // Control de capturas
				   {
				 	
				 	 system("cls");
					 do // verificacion de informacion
					   {
					     do
					       {
						     printf("\nMatricula: ");
						     fflush(stdin);
       				 	     gets(aux1);
       					     pp->mat=atoi(aux1);
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
						      	  gets(aux1);
						      	  pp->cal[j]=atof(aux1);
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
				   }while(op == 1);  // cierre del ciclo
				 break;
				 
	    case 2: pp=&al[0];
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
		       printf("\n\n");
  			   system("pause");		 
  			   break;
  			
  	    case 3: pp=&al[0];
  	            printf("\nAlUMNOS CON CALIFICACION MAYOR A 9 EN EL TERCER PARCIAL");
			    system("cls");
				for(j=0;j<i;j++)
				   {
					 if(pp->cal[2]>95)
						printf("\n\n\n\t Nombre del alumno: %s\n\t Matricula del alumno: %d\n\t Calificacion: %.2f",pp->nom, pp->mat, pp->cal[2]);
						pp++;
			       }
			   printf("\n\n");
  			   system("pause");		 
  			   break;
  	
  	    case 4: pp=&al[0];
  			    printf("\nPROMEDIO GENERAL DE ALUMNOS EN EL CUARTO PARCIAL: ");
			
			    system("cls");
			    suma=0;
				for(j=0;j<i;j++)
				  {
					suma = suma + pp->cal[3];
					promgen=(float)(suma/i);
					pp++;
				  }	
				
				printf("\n\n\n\tPromedio general del cuarto examen: %.2f",promgen);
			    printf("\n\n");
  			    system("pause");		 
  			    break;
	
	    case 5: 
				/*
				pp=&al[0];
	            system("cls");
			    printf("\n\n\n\t REPORTE ALUMNOS ORDENADO DE  MAYOR A MENOR PROMEDIO: ");
		
			    for(j=0;j<i;j++)
			      {
				    suma1=0.0;
				    for(k=0;k<5;k++)
				    suma1 = suma1 + pp->cal[k];
				    pp->prom = suma1 / 5;
				    pp++;
			      }
			  
			    pp=&al[0];
				for(j=0;j<i-1;j++)
			      {
				    cal=pp;
			        for(m=j;m<i;m++)
					  {
				        if( pp->prom <= cal->prom)
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
		
		       pp=&al[0];
			   for(j=0;j<i;j++)
		         {
			       printf("\n\n\n\n\t Nombre del alumno: %s\n\t Matricula: %d\n\t Promedio: %.2f", pp->nom, pp->mat, pp->prom);
			       pp++;
		         }
		      */
		      pp=&al[0];
		      for(j=0;j<i-1;j++)
			      {
				    cal=pp;
			        for(m=j;m<i;m++)
					  {
				        if( pp->prom <= cal->prom)
				          {
					        aux=*pp;
					        *pp=*cal;
					       *cal=aux;
				          }
				        cal++;
			          }
			        pp++;
		          }
		      
		      pp=&al[0];
			   for(j=0;j<i;j++)
		         {
			       printf("\n\n\n\n\t Nombre del alumno: %s\n\t Matricula: %d\n\t Promedio: %.2f", pp->nom, pp->mat, pp->prom);
			       pp++;
		         }
		      
		       printf("\n\n");
  		       system("pause");		 
  		       break;
  		 
  	     case 6: printf("\n\n\n\t\t\t SALIDA DEL PROGRAMA\n\n");
  	             break;
       } // cierre del switch
  
    }while(op != 6);
  

  	printf("\n\n\n\n\n");
  	system("pause");
  	return 0;
}
		
