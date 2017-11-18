#include <stdio.h>
#define MAX 500


void le_matriz(double mat[MAX][MAX],int l, int c){
    int i,j;
    printf("Entre com os valores da matriz.\n");
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            printf("M[%d][%d] = ",i,j);
            scanf("%lf",&mat[i][j]);
        }
    }

}


void imprime_matriz(double mat[MAX][MAX],int l, int c){
    int i,j;
    printf("Imprimindo a matriz.\n");
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            printf("%lf ",mat[i][j]);
        }
        printf("\n");
    }
}

void troca_coluna(double mat[MAX][MAX],int l,int coluna_1, int coluna_2){
    for(int i=0;i<l;i++){
        int aux = mat[i][coluna_1];
        mat[i][coluna_1] = mat[i][coluna_2];
        mat[i][coluna_2] = aux;
    }
}

void executa_trocas(double mat[MAX][MAX],int l,int c){
    int i;
    for(i=0;i<c/2;i++){
        troca_coluna(mat,l,i,c-i-1);
    }
}



int main(void){
    double mat[MAX][MAX];
    int l,c;
    printf("Digite o número de linhas da matriz: ");
    scanf("%d",&l);
    printf("Digite o número de colunas da matriz: ");
    scanf("%d",&c);
    le_matriz(mat, l, c);
    printf("Trocando colunas.\n");
    executa_trocas(mat,l,c);
    printf("Matriz com colunas trocadas.\n");
    imprime_matriz(mat,l,c);
    return 0;
}
