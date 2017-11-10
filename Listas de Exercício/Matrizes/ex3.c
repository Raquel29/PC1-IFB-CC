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

void imprime_diagonal_maior_soma(double mat[MAX][MAX],int n){
    int i,j,k;
    double  maior_soma  = 0;
    int diagonal_escolhida = 0;
    for(k=-n+1;k<n;k++){
        i = k < 0? -k : 0;
        double soma_diagonal = 0;
        while(i<n){
            j = i+k;
            soma_diagonal += mat[i][j];
            i++;
        }
        if(soma_diagonal>maior_soma){
            maior_soma = soma_diagonal;
            diagonal_escolhida = k;
        }
    }
    printf("A diagonal com maior soma tem soma: %lf.\n",maior_soma);
    printf("A diagonal com maior soma possui os seguintes elementos:\n");
    i = diagonal_escolhida < 0 ? -diagonal_escolhida : 0;
    while(i<n){
        j = i + diagonal_escolhida;
        printf("Mat[%d][%d] = %lf.\n",i,j,mat[i][j]);
        i++;
    }
}




int main(void){
    double mat[MAX][MAX], mat_transposta[MAX][MAX];
    int n;
    printf("Digite a dimensão da matriz quadrada: ");
    scanf("%d",&n);
    le_matriz(mat, n,n);
    imprime_diagonal_maior_soma(mat,n);
    return 0;
}
