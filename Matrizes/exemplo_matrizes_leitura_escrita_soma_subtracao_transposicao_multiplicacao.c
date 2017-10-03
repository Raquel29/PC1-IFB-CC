#include <stdio.h>
#define MAX 100
void le_matriz(double mat[MAX][MAX],
    int l, int c){
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
int soma_matriz(double mat1[MAX][MAX],int l1,int c1, double mat2[MAX][MAX],int l2,int c2,double res[MAX][MAX]){
    if(l1!=l2 || c1!=c2){
        return 0;
    }
    int i,j;
    for(i=0;i<l1;i++){
        for(j=0;j<c1;j++){
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return 1;
}

int subtrai_matriz(double mat1[MAX][MAX],int l1,int c1, double mat2[MAX][MAX],int l2,int c2,double res[MAX][MAX]){
    if(l1!=l2 || c1!=c2){
        return 0;
    }
    int i,j;
    for(i=0;i<l1;i++){
        for(j=0;j<c1;j++){
            res[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    return 1;
}


void transpoe_matriz(double mat[MAX][MAX],int l,int c,double res[MAX][MAX]){
    int i,j;
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            res[j][i] = mat[i][j];
        }
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
    int l1,c1,l2,c2;
    double mat1[MAX][MAX];
    double mat2[MAX][MAX];
    double res[MAX][MAX];
    printf("Entre as dimensões da matriz 1: ");
    scanf("%d%d",&l1,&c1);
    le_matriz(mat1,l1,c1);
    printf("Entre as dimensões da matriz 2: ");
    scanf("%d%d",&l2,&c2);
    le_matriz(mat2,l2,c2);
    imprime_matriz(mat1,l1,c1);
    imprime_matriz(mat2,l2,c2);

    if(soma_matriz(mat1,l1,c1,mat2,l2,c2,res)){
        printf("Soma efetuada.\n");
        imprime_matriz(res, l1, c1);
    }
    else{
        printf("Impossível fazer a soma.\n");
    }

    if(subtrai_matriz(mat1,l1,c1,mat2,l2,c2,res)){
        printf("Subtração efetuada.\n");
        imprime_matriz(res, l1, c1);
    }
    else{
        printf("Impossível fazer a subtração.\n");
    }
    transpoe_matriz(mat1,l1,c1,res);
    imprime_matriz(res,c1,l1);
    if(multiplica_matriz(mat1, l1, c1, mat2, l2, c2, res)){
        printf("Multiplicação efetuada.\n");
        imprime_matriz(res,l1,c2);
    }
    else{
        printf("Impossível multiplicar a matriz.\n");
    }
    return 0;
}
