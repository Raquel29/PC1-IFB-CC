#include <stdio.h>
#include <limits.h>

#define MAX 1000


void imprime_matriz(int mat[MAX][MAX],int l, int c){
    int i,j;
    printf("Imprimindo a matriz.\n");
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

void inicializa_quadrado_magico(int mat[MAX][MAX],int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            mat[i][j] = 0;
        }
    }
}

void proxima_posicao(int mat[MAX][MAX],int n,int* pos_i,int* pos_j){
    int aux_i = *pos_i-1, aux_j = *pos_j+1;
    if(aux_i<0){
        aux_i = n-1;
    }
    if(aux_j==n){
        aux_j = 0;
    }
    if(mat[aux_i][aux_j]!=0){
        aux_i = *pos_i + 1 == n ? 0 : *pos_i+1;
        aux_j = *pos_j;
    }
    *pos_i = aux_i;
    *pos_j = aux_j;
}
void gera_quadrado_magico(int mat[MAX][MAX],int n){
    inicializa_quadrado_magico(mat,n);
    int pos_i = 0;
    int pos_j = n/2;
    int total = n*n;
    int count = 1;
    while(total){
        mat[pos_i][pos_j] = count;
        proxima_posicao(mat,n,&pos_i,&pos_j);
        count++;
        total--;
    }
}


int main(void){
    int mat[MAX][MAX];
    int n;
    printf("Digite a dimensão da matriz: ");
    scanf("%d",&n);
    gera_quadrado_magico(mat,n);
    imprime_matriz(mat,n,n);
    return 0;
}
