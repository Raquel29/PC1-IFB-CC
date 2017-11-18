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

int compara_inverso(char* nome_1,char* nome_2){
    if(strlen(nome_1) != strlen(nome_2)){
        return 0;
    }
    int i_1 = 0;
    int i_2 = strlen(nome_1) - 1;
    while(i_1 < strlen(nome_1)){
        if(nome_1[i_1]!=nome_2[i_2]){
            return 0;
        }
        i_1++;
        i_2--;
    }
    return 1;
}

void verifica_inversos(char nomes[MAX_L][MAX_C],int l){
    int i,j;
    for(i=0;i<l;i++){
        printf("Verificando os inversos do %d nome que é igual a %s\n",i+1,nomes[i]);
        for(j=0;j<l;j++){
            if(i!=j){
                if(compara_inverso(nomes[i],nomes[j])){
                    printf("O nome %d que é igual a %s corresponde ao inverso do nome %d\n",j+1,nomes[j],i+1);
                }
            }
        }
    }
}



int main(void){
    char nomes[MAX_L][MAX_C];
    int l;
    printf("Digite o número de nomes: ");
    scanf("%d%*c",&l);
    le_matriz(nomes, l,MAX_C-1);
    verifica_inversos(nomes,l);
    return 0;
}
