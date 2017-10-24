#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char* le_arquivo(FILE* arq){
	int count = 0;
	char c;
	char* buffer;
	while(fscanf(arq,"%c",&c)!=EOF){
		count++;
	}
	buffer = malloc(sizeof(char)*(count+1));
	count = 0;
	rewind(arq);
	while(fscanf(arq,"%c",&c)!=EOF){
		buffer[count++] = c;
	}
	buffer[count] = '\0';
	return buffer;
}

void manipula_arquivo(FILE* arq,char* buffer){
	int i=0;
	rewind(arq);
	while(buffer[i]!='\0'){
		if(islower(buffer[i])){
			buffer[i] = toupper(buffer[i]);
		}
		else if(isupper(buffer[i])){
			buffer[i] = tolower(buffer[i]);
		}
		fprintf(arq,"%c",buffer[i]);
		i++;
	}	
}

int main(int argc, char* argv[]){
	FILE* arq;
	if(argc!=2){
		printf("Uso: ./altera_arquivo <arquivo_de_entrada>.\n");
		exit(EXIT_FAILURE);
	}
	arq = fopen(argv[1],"r+");
	if(arq==NULL){
		printf("Impossivel abrir arquivo.\n");
		exit(EXIT_FAILURE);
	}
	char* buffer = le_arquivo(arq);
	manipula_arquivo(arq,buffer);
	return 0;
}