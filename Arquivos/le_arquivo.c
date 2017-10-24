#include <stdio.h>
#include <stdlib.h>
/*
 *  Le um arquivo passado como parâmetro
 * de linha de comando e imprime o conteúdo
 * do arquivo na tela
 */
int main(int argc, char* argv[]){
	FILE* arq;
	char c;
	if(argc!=2){
		printf("Uso: ./le_arquivo <caminho_do_arquivo>.\n");
		exit(EXIT_FAILURE);
	}
	arq = fopen(argv[1],"r");
	if(arq==NULL){
		printf("Erro ao abrir o arquivo.\n");
		exit(EXIT_FAILURE);
	}
	while(fscanf(arq,"%c",&c)!=EOF){
		printf("%c",c);
	}
	fclose(arq);
	return 0;
}