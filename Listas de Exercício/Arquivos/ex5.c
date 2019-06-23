#include <stdio.h>
#include <stdlib.h>


void le_dimensao_matriz(FILE* arq,int* n,int* m){
    fscanf(arq,"%d %d",n,m);
}

double** le_matriz(FILE* arq,int n,int m){
    int i,j;
    double** matriz = malloc(sizeof(double*) * n);
    for(i=0;i<n;i++){
        matriz[i] = malloc(sizeof(double)*m);
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            fscanf(arq,"%lf",&matriz[i][j]);
        }
    }
    return matriz;
}

double** transpoe_matriz(double** matriz,int n,int m){
    int i,j;
    double** matriz_transposta = malloc(sizeof(double*)*m);
    for(i=0;i<m;i++){
        matriz_transposta[i] = malloc(sizeof(double)*n);
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            matriz_transposta[j][i] = matriz[i][j];
        }
    }
    return matriz_transposta;
}

void escreve_matriz(double** matriz,int n,int m,FILE* arq){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            fprintf(arq,"%lf.2",matriz[i][j]);
            if(j<m-1){
                fprintf(arq," ");
            }
            else{
                fprintf(arq,"\n");
            }
        }
    }
}

void libera_matriz(double** matriz,int n){
    int i;
    for(i=0;i<n;i++){
        free(matriz[i]);
    }
    free(matriz);
}

int main(int argc, char** argv){
    FILE *arq1,*arq2;
    if(argc!=3){
        printf("Uso: ./executavel <arquivo-matriz> <arquivo-matriz-transposta>.\n");
        return 0;
    }
    arq1 = fopen(argv[1],"r");
    arq2 = fopen(argv[2],"w");
    if(arq1==NULL){
        printf("Impossivel abrir o arquivo %s.\n",argv[1]);
        exit(EXIT_FAILURE);
    }
    if(arq2==NULL){
        printf("Impossivel abrir o arquivo %s.\n",argv[2]);
        exit(EXIT_FAILURE);
    }
    int n,m;
    le_dimensao_matriz(arq1,&n,&m);
    double** matriz =  le_matriz(arq1,n,m);
    double** matriz_transposta = transpoe_matriz(matriz,n,m);
    escreve_matriz(matriz_transposta,m,n,arq2);
    libera_matriz(matriz,n);
    libera_matriz(matriz_transposta,m);
    return 0;
}