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

int multiplica_matriz(double mat1[MAX][MAX], int l1,int c1,double mat2[MAX][MAX],int l2,int c2,double res[MAX][MAX]){
    int i,j,k;
    if(c1!=l2){
        return 0;
    }
    for(i=0;i<l1;i++){
        for(j=0;j<c2;j++){
            res[i][j] = 0;
            for(k=0;k<c1;k++){
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return 1;
}


int main(void){
    double mat_a[MAX][MAX],mat_b[MAX][MAX], mat_c[MAX][MAX];

    int l1,c1,l2,c2;
    printf("Digite o número de linhas da primeira matriz: ");
    scanf("%d",&l1);
    printf("Digite o número de colunas da primeira matriz: ");
    scanf("%d",&c1);
    printf("Leitura da matriz A\n");
    le_matriz(mat_a,l1,c1);

    printf("Digite o número de linhas da segunda matriz: ");
    scanf("%d",&l2);
    printf("Digite o número de colunas da segunda matriz: ");
    scanf("%d",&c2);
    printf("Leitura da matriz B\n");
    le_matriz(mat_b,l2,c2);

    if(!multiplica_matriz(mat_a,l1,c1,mat_b,l2,c2,mat_c)){
        printf("Impossível multiplicar matrizes com estas dimensões.\n");
    }
    else{
        imprime_matriz(mat_c,l1,c2);
    }

    return 0;
}
