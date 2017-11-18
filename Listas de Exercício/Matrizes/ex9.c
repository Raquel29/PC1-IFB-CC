#include <stdio.h>
#include <string.h>

#define MAX_L 1000
#define MAX_C 81

void le_matriz(char mat[MAX_L][MAX_C],int l,int c){
    int i;
    printf("Entre com os nomes.\n");
    for(i=0;i<l;i++){
        printf("Nome[%d] = ",i);
        fgets(mat[i],c,stdin);
        if(mat[i][strlen(mat[i])-1]=='\n') {
                mat[i][strlen(mat[i])-1] = '\0';
        }
    }
}


void imprime_matriz(char mat[MAX_L][MAX_C],int l, int c){
    int i;
    printf("Imprimindo nomes na ordem inversa.\n");
    for(i=l-1;i>=0;i--){
        printf("%s\n",mat[i]);
    }
}




int main(void){
    char nomes[MAX_L][MAX_C];
    int l;
    printf("Digite o número de nomes: ");
    scanf("%d%*c",&l);
    le_matriz(nomes, l,MAX_C-1);
    imprime_matriz(nomes,l,MAX_C-1);
    return 0;
}
