#include <stdio.h>
#include <limits.h>
#define MAX 1000

void le_matriz(int mat[MAX][MAX],int l, int c){
    int i,j;
    printf("Entre com os valores da matriz.\n");
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            printf("M[%d][%d] = ",i,j);
            scanf("%d",&mat[i][j]);
        }
    }
}

int verifica_anti_diagonal(int mat[MAX][MAX], int  n, int soma){
    int soma_2 = 0;
    int i;
    for(i=0;i<n;i++){
        soma_2 += mat[n-i-1][i];
    }
    return soma == soma_2;
}

int verifica_linha(int mat[MAX][MAX],int n,int i,int soma){
    int j;
    int soma_2 = 0;
    for(j=0;j<n;j++){
        soma_2+= mat[i][j];
    }
    return soma_2 == soma;
}

int verifica_coluna(int mat[MAX][MAX],int n,int i,int soma){
    int j;
    int soma_2 = 0;
    for(j=0;j<n;j++){
        soma_2+= mat[j][i];
    }
    return soma_2 == soma;
}

int verifica_quadrado_magico(int mat[MAX][MAX],int n){
    int soma = 0;
    int i;
    for(i=0;i<n;i++){
        soma += mat[i][i];
    }
    if(!verifica_anti_diagonal(mat,n,soma)){
        return 0;
    }
    for(i=0;i<n;i++){
        if(!verifica_linha(mat,n,i,soma))
            return 0;
        if(!verifica_coluna(mat,n,i,soma)){
            return 0;
        }
    }
    return 1;

}



int main(void){
    int mat[MAX][MAX];
    int n;
    printf("Digite a dimensão da matriz: ");
    scanf("%d",&n);
    le_matriz(mat, n,n);
    if(verifica_quadrado_magico(mat,n)){
        printf("É um quadrado mágico.\n");
    }
    else{
        printf("Não é um quadrado mágico.\n");
    }
    return 0;
}
