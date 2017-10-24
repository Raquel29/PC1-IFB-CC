#include <stdio.h>
#include <stdlib.h>
int main(void){
	FILE* arq;
	char nome[50];
	double nota;
	arq = fopen("dados.txt","r");
	if(arq==NULL){
		printf("Erro ao abrir o arquivo");
		exit(EXIT_FAILURE);
	}
	while(fscanf(arq,"%49[^\n]s%*c",nome)!=EOF && 
		fscanf(arq,"%lf\n",&nota)!=EOF){
		printf("Nome = %s.\nNota = %lf.\n",nome,nota);
	}
	fclose(arq);
	return 0;
}