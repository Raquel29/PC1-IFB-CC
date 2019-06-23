#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct carro_t{
    char fabricante[50];
    char modelo[50];
    int ano;
    double preco;
}carro_t;


void imprime_registro(const carro_t* carro){
    printf("Fabricante = %s\n",carro->fabricante);
    printf("Modelo = %s\n",carro->modelo);
    printf("Ano = %d\n",carro->ano);
    printf("preco = %lf\n\n",carro->preco);
}

int le_registro(FILE* arq,carro_t* carro){
    char linha[200];
    char* tkn; //token
    if(fgets(linha,200,arq)!=NULL){
        tkn = strtok(linha,",\n");
        strcpy(carro->fabricante,tkn);
        tkn = strtok(NULL,",\n");
        strcpy(carro->modelo,tkn);
        tkn = strtok(NULL,",\n");
        carro->ano = atoi(tkn);
        tkn = strtok(NULL,",\n");
        carro->preco = atof(tkn);
        return 1;
    }
    return 0;
}

//argv[0] = nome do programa
//argv[1] = nome do arquivo csv
int main(int argc,char* argv[]){
    char cabecalho[200];
    if(argc!=2){
        printf("Uso: ./<nome do executavel> <arquivo csv>");
        return 0;
    }
    FILE* arq = fopen(argv[1],"r");
    fgets(cabecalho,200,arq);
    carro_t carro;
    while(le_registro(arq,&carro)){
        imprime_registro(&carro);
    }

    fclose(arq);

    return 0;
}
