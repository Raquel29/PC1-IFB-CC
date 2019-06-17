#include <stdio.h>
#include <ctype.h>
void substitui_vogais(FILE* arq){
	char c;
	while(fscanf(arq,"%c",&c)!=EOF){
		if(c=='a' || c=='e' || c=='i'
			|| c=='o' || c=='u'){
			c = toupper(c);
		}
		fseek(arq,-1*sizeof(char),SEEK_CUR);
		fprintf(arq,"%c",c);
	}
}

int main(int argc, char** argv){
	if(argc !=2){
		printf("Uso: ./executavel <caminho do arquivo>.\n");
		return 0;
	}
	FILE* arq = fopen(argv[1],"r+");
	if(arq == NULL){
		printf("Impossivel abrir %s\n",argv[1]);
		return 1;
	}
	substitui_vogais(arq);
}