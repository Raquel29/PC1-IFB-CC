#include <stdio.h>
#include <stdlib.h>

int main(int argc,char* argv[]){
	FILE *arqin, *arqout;
	char c;
	if(argc != 3){
		printf("Uso: ./copia_arquivo <arquivo_de_entrada> <arquivo_de_saida>.\n");
		exit(EXIT_FAILURE);
	}
	arqin = fopen(argv[1],"r");
	arqout = fopen(argv[2],"w");
	if(arqin==NULL || arqout==NULL){
		printf("Erro ao abrir arquivos.\n");
		exit(EXIT_FAILURE);
	}
	while(fscanf(arqin,"%c",&c)!=EOF){
		fprintf(arqout,"%c",c);
	}
	fclose(arqin);
	fclose(arqout);
}