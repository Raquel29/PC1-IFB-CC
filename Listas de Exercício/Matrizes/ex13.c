#include <stdio.h>
#include <limits.h>
#include <string.h>
#define MAX 1000

void le_matriz(char mat[MAX][MAX],int l, int c){
    int i;
    printf("Entre com os valores da matriz (apenas ' ' e '*').\n");
    for(i=0;i<l;i++){
        printf("Digite a %d linha: ",i+1);
        fgets(mat[i],MAX-1,stdin);
        if(mat[i][strlen(mat[i])]=='\n'){
            mat[i][strlen(mat[i])]='\0';
        }
    }

}

void imprime_matriz(char mat[MAX][MAX],int l){
    int i;
    for(i=0;i<l;i++){
        printf("%s\n",mat[i]);
    }
}

int nro_vizinhos(char mat[MAX][MAX],int i,int j,int l,int c){
    int nro_vizinhos = 0;
    int ii,jj;
    for(ii=i-1;ii<=i+1;ii++){
        for(jj=j-1;jj<=j+1;jj++){
            // Verifica se o vizinho ocupa uma posição válida na matriz
            // diferente da posição original e se é um '*'
            if( !((ii==i) && (jj==j))  && (ii>=0) && (ii<l) && (jj>=0) && (jj<c) && (mat[ii][jj]=='*')){
                nro_vizinhos++;
            }
        }
    }
    return nro_vizinhos;
}

void computa_proxima_geracao(char m1[MAX][MAX],int l,int c,char m2[MAX][MAX]){
    int i,j;
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            int n_vzo = nro_vizinhos(m1,i,j,l,c);
            if(m1[i][j]=='*'){
                if(n_vzo<2){
                    m2[i][j] = ' ';
                }
                else if(n_vzo>3){
                    m2[i][j] = ' ';
                }
                else{
                    m2[i][j] = '*';
                }
            }
            else{
                if(n_vzo == 3){
                    m2[i][j] = '*';
                }
                else{
                    m2[i][j] = ' ';
                }
            }
        }
        m2[i][j] = '\0';
    }
}

void jogo_da_vida(char mat[MAX][MAX],int l, int c,int k){
    char mat_aux[MAX][MAX];
    for(int i=0;i<=k;i++){
        printf("\n\n\n --- Geração %d --- \n\n\n",i);
        if(i%2==0){
            imprime_matriz(mat,l);
            computa_proxima_geracao(mat,l,c,mat_aux);
        }
        else{
            imprime_matriz(mat_aux,l);
            computa_proxima_geracao(mat_aux,l,c,mat);
        }

    }
}

int main(void){
    char mat[MAX][MAX];
    int l,c,k;
    printf("Digite a quantidade de linhas da matriz: ");
    scanf("%d",&l);
    printf("Digite a quantidade de colunas da matriz: ");
    scanf("%d%*c",&c);

    le_matriz(mat, l,c);
    printf("Digite o número de gerações: ");
    scanf("%d",&k);
    printf("Simulando o jogo da vida por %d gerações.\n",k);
    jogo_da_vida(mat,l,c,k);
    return 0;
}
