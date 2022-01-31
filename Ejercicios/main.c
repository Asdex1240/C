#include <stdlib.h>
#include <stdio.h>

int main(){
	int n;
	printf("Escribe un numero\n");
	printf("Write a number\n");
	scanf("%d",&n);
	if(n % 2 ==0){
		printf("%d es par\n",n);
		printf("%d is even\n",n);
	}else{
		printf("%d es impar\n",n);
		printf("%d is odd\n",n);
	}
	system("PAUSE");
	return 0;
}
