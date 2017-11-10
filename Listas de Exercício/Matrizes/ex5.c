#include <stdio.h>
#include <limits.h>
#define MAX 500

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

void busca_submatriz(int mat[MAX][MAX],int l,int c, int k){
    int i,j,ii,jj;
    int maior_soma=INT_MIN,pos_i,pos_j;
    for(i=0;i<l-k+1 ;i++){
        for(j=0;j<c-k+1;j++){
            int soma = 0;
            for(ii=i;ii<i+k;ii++){
                for(jj=i;jj<j+k;jj++){
                    soma += mat[ii][jj];
                }
            }
            if(soma > maior_soma){
                maior_soma = soma;
                pos_i = i;
                pos_j = j;
            }
        }
    }
    printf("Posição da submatriz com maior soma = (%d,%d).\n",pos_i,pos_j);
    printf("Maior soma = %d.\n",maior_soma);
}



int main(void){
    int mat[MAX][MAX];
    int l,c,k;
    printf("Digite a quantidade de linhas da matriz: ");
    scanf("%d",&l);
    printf("Digite a quantidade de colunas da matriz: ");
    scanf("%d",&c);

    le_matriz(mat, l,c);

    printf("Digite a dimensão da submatriz: ");
    scanf("%d",&k);
    if(k > l || k > c){
        printf("Dimensão inválida.\n");
        return 0;
    }
    busca_submatriz(mat,l,c,k);
    return 0;
}
