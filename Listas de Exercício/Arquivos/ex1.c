#include <stdio.h>


void concatena(FILE* arq1, FILE* arq2, FILE* arq3){
    char c;
    while((c=fgetc(arq1))!=EOF){
        fputc(c,arq3);
    }
    while((c=fgetc(arq2))!=EOF){
        fputc(c,arq3);
    }
}
// argv[0] = Nome do programa
// argv[1] = Caminho do primeiro arquivo
// argv[2] = Caminho do segundo arquivo
// argv[3] = Caminho do terceiro arquivo
int main(int argc,char* argv[]){
    FILE *arq1, *arq2, *arq3;
    if(argc != 4){
        printf("Uso: ./<executavel> <arq1> <arq2> <arq3>");
        return 0;
    }
    arq1 = fopen(argv[1],"r");
    arq2 = fopen(argv[2],"r");
    arq3 = fopen(argv[3],"w");
    if(arq1 == NULL || arq2 == NULL || arq3 == NULL){
        printf("Impossível abrir arquivo(s).\n");
        return 0;
    }
    concatena(arq1,arq2,arq3);
}
