#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char aux[' '];
int p,y,i,c=0,n=0;
double num;

int main()
{
	
	do
	{
		
		//system("cls");
		printf("\n\t Ingrese la cadena: ");
		fflush(stdin);
		gets(aux);
		y=strlen(aux);
		c=0;
		n=0;
		for(i=0;i<y;i++)
		{
			
			
			if(isdigit(aux[i]) || aux[i]=='.' || aux[i]=='-' )
			{
				p=1;
				if(aux[i]==46)
					c++;
				if(aux[i]=='-')
					n++;		
			}
			else
				p=0;
			
			if(p==0 || c>1 || n>1)
					{
						
						p=0;
						printf("\n\n\t ERROR, DATO MAL INTRODUCIDO \n\n");
						break;	
											
					}					
		}
		if(y==0)
			p=0;
			
	}	while(p==0);
	
	num= atof(aux);
	
	printf("%.2f\n\n",num);
	
	system("pause");
	return 0;
}
