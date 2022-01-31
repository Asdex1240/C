#include<stdio.h>
//#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char Aux[' '];
int i,p,y,num;
int main()
{
	do{
	    printf("\n Introduzca un valor numerico: ");	
        fflush(stdin);
        gets(Aux);//se lee los datos introducidos
        y = strlen(Aux);
     
	    for(i=0;i < y;i++)
	      {
             if(isdigit(Aux[i]))
                p = 1;	
	         else
         		p = 0;
	         if(p ==0)
         	   {
           		 printf("\n\n Error,dato mal introducido\n\n ");
		   		 break;
         	   }
	  	 }
        if(y==0)
	      p=0;
	}while(p==0);
   
   num = atoi(Aux);
   printf("\n\n\n\t Valor leido: %d",num);
}
