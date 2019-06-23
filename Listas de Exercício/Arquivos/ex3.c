#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void merge(FILE* arq1,FILE* arq2,FILE* arq3){
    int nbytes1,nbytes2;
    int menor;
    int num1,num2;
    int escolhido = -1;
    nbytes1 = fread(&num1,sizeof(int),1,arq1);
    nbytes2 = fread(&num2,sizeof(int),1,arq2);
    while(nbytes1>0 && nbytes2>0){
        if(num1<=num2){
            menor = num1;
            escolhido = 1;  
        }
        else{
            menor = num2;
            escolhido = 2;
        }
        fwrite(&menor,sizeof(int),1,arq3);
        if(escolhido == 1){
            nbytes1 = fread(&num1,sizeof(int),1,arq1);
        }
        else{
            nbytes2 = fread(&num2,sizeof(int),1,arq2);
        }
    }
    while(nbytes1>0){
        nbytes1 = fread(&num1,sizeof(int),1,arq1);
        fwrite(&num1,sizeof(int),1,arq3);
    }
    while(nbytes2>0){
        nbytes2 = fread(&num2,sizeof(int),1,arq2);
        fwrite(&num2,sizeof(int),1,arq3);   
    }
}

int main(int argc, char** argv){
    FILE *arq1,*arq2;
    FILE* arq3;
    if(argc!=4){
        printf("Erro.\nUso: ./<nome do executavel> <arquivo binario 1> <arquivo binario 2> <arquivo binario de saida>\n");
        return 0;
    }
    arq1 = fopen(argv[1],"rb");
    arq2 = fopen(argv[2],"rb");
    if(arq1 == NULL || arq2 == NULL){
        printf("Impossivel abrir os arquivos de entrada.\n");
        exit(EXIT_FAILURE);
    }
    arq3 = fopen(argv[3],"wb");
    if(arq3==NULL){
        printf("Impossivel abrir o arquivo de saida.\n");
        exit(EXIT_FAILURE);
    }
    merge(arq1,arq2,arq3);
    return 0;
}
