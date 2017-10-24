#include <stdio.h>

//argc = quantidade de parâmetros
//argv = parâmetros propriamente ditos
int main(int argc, char* argv[]){
	printf("Número de parâmetros = %d.\n",argc);
	int i;
	for(i=0;i<argc;i++){
		printf("Parâmetro %d = %s.\n",i,argv[i]);
	}
	return 0;
}