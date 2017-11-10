#include <stdio.h>
#define MAX 500

void transpoe_matriz(double mat[MAX][MAX],int l,int c,double res[MAX][MAX]){
    int i,j;
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            res[j][i] = mat[i][j];
        }
    }
}


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



int main(void){
    double mat[MAX][MAX], mat_transposta[MAX][MAX];
    int l1,c1;
    printf("Digite o número de linhas da matriz: ");
    scanf("%d",&l1);
    printf("Digite o número de colunas da matriz: ");
    scanf("%d",&c1);
    le_matriz(mat, l1, c1);
    printf("Transpondo a matriz.\n");
    transpoe_matriz(mat,l1,c1,mat_transposta);
    printf("Matriz transposta.\n");
    imprime_matriz(mat_transposta,c1,l1);
    return 0;
}
