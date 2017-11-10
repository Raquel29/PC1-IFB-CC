#include <stdio.h>
#define MAX 500


int nro_cidades_chegam(int mat[MAX][MAX],int n,int k){
    int nro = 0;
    int i;
    for(i=0;i<n;i++){
        if(i!=k && mat[i][k]){
            nro++;
        }
    }
    return nro;
}

int nro_cidades_saem(int mat[MAX][MAX],int n,int k){
    int nro = 0;
    int i;
    for(i=0;i<n;i++){
        if(i!=k && mat[k][i]){
            nro++;
        }
    }
    return nro;
}

void letra_a(int mat[MAX][MAX],int n){
    int k;
    printf("Digite o identificador da cidade: ");
    scanf("%d",&k);
    printf("O número de cidades que chegam à cidade %d é %d\n",k,nro_cidades_chegam(mat,n,k));

    printf("O número de cidades que saem da cidade %d é %d\n",k,nro_cidades_saem(mat,n,k));
}

void lista_entradas(int mat[MAX][MAX],int n,int k){
    int i;
    printf("As cidades que possuem saidas para a cidade %d são: ",k);
    for(i=0;i<n;i++){
        if(i!=k && mat[i][k]){
            printf("%d ",i);
        }
    }
    printf("\n");
}

int verifica_mao_dupla(int mat[MAX][MAX],int n,int k){
    int i;
    int mao_dupla = 1;
    for(i=0;i<n;i++){
        if(i!=k && ((!mat[i][k] && mat[k][i]) || (mat[i][k] && !mat[k][i]))){
            mao_dupla = 0;
        }
    }
    return mao_dupla;
}

void letra_b(int mat[MAX][MAX],int n){
    int max = 0;
    int id_cidade = 0;
    int i;
    for(i=0;i<n;i++){
        int nro = nro_cidades_chegam(mat, n, i);
        if(nro > max){
            max = nro;
            id_cidade = i;
        }
    }
    printf("A cidade que mais chegam estradas é a cidade %d.\n",id_cidade);
}

void letra_c(int mat[MAX][MAX],int n){
    int k;
    printf("Digite o identificador da cidade: ");
    scanf("%d",&k);
    if(verifica_mao_dupla(mat,n,k)){
        printf("Todas as estradas de %d são de mão dupla.\n",k);
    }
    else{
        printf("Nem todas as estradas de %d são de mão dupla.\n",k);
    }
}

void letra_d(int mat[MAX][MAX],int n){
    int k;
    printf("Digite o identificador da cidade: ");
    scanf("%d",&k);
    lista_entradas(mat,n,k);
}

void letra_e(int mat[MAX][MAX],int n){
    int i;
    printf("Imprimindo cidades isoladas.\n");
    for(i=0;i<n;i++){
        if(!nro_cidades_chegam(mat, n, i) &&
            !(nro_cidades_saem(mat, n, i))){
            printf("A cidade %d é isolada.\n",i);
        }
    }
}

void letra_f(int mat[MAX][MAX],int n){
    int i;
    printf("Imprimindo as cidades que não possuem saídas.\n");
    for(i=0;i<n;i++){
        if( !nro_cidades_saem(mat, n, i)){
            printf("A cidade %d não possui saídas.\n",i);
        }
    }
}

void letra_g(int mat[MAX][MAX],int n){
    int i;
    printf("Imprimindo as cidades que não possuem entradas.\n");
    for(i=0;i<n;i++){
        if( nro_cidades_chegam(mat, n, i) && !nro_cidades_saem(mat, n, i) ){
            printf("A cidade %d possui entradas, mas não saídas.\n",i);
        }
    }
}


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


void imprime_menu(void){
    printf("\n\n**** Menu ****\n\n");
    printf("1) Verificar quantas cidades saem e quantas chegam de uma determinada cidade.\n");
    printf("2) Verificar qual das cidades possui o maior número de entradas.\n");
    printf("3) Verificar se uma cidade só possui vias de mão dupla.\n");
    printf("4) Listar as cidades que possuem saída para uma determinada cidade.\n");
    printf("5)  Listar as cidades isoladas.\n");
    printf("6) Listar as cidades que não possuem saídas.\n");
    printf("7) Listar as cidades que possuem entradas mas não saídas.\n");
    printf("8) Sair.\n");
    printf("Digite uma opcão (1 a 8): ");
}

void executa_funcao(int mat[MAX][MAX],int n, int opcao){
    switch (opcao) {
        case 1: letra_a(mat, n); break;
        case 2: letra_b(mat, n); break;
        case 3: letra_c(mat, n); break;
        case 4: letra_d(mat, n); break;
        case 5: letra_e(mat, n); break;
        case 6: letra_f(mat, n); break;
        case 7: letra_g(mat, n); break;
    }
}

int main(void){
    int mat[MAX][MAX];
    int n;
    int opcao;
    printf("Digite a dimensão da matriz quadrada: ");
    scanf("%d",&n);
    le_matriz(mat, n,n);
    do{
        imprime_menu();
        scanf("%d",&opcao);
        executa_funcao(mat,n,opcao);
    }while(opcao!=8);
    return 0;
}
