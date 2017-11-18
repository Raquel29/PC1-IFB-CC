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

int compara_nomes(char* nome_1,char* nome_2){
    /** A função strcmp poderia ser utilizada no lugar desta **/
    int tam_1 = strlen(nome_1);
    int tam_2 = strlen(nome_2);
    int i = 0;
    if(tam_1 != tam_2){
        return 0;
    }
    while(i<tam_1){
        if(nome_1[i]!=nome_2[i]){
            return 0;
        }
        i++;
    }
    return 1;
}

void verifica_nomes(char nomes[MAX_L][MAX_C],int l){
    int i,j;
    int max = 0;
    int max_i = -1;
    for(i=0;i<l;i++){
        printf("Verificando a quantidade de ocorrências do %d nome que é igual a %s\n",i+1,nomes[i]);
        int cont = 1;
        for(j=i+1;j<l;j++){
            if(i!=j){
                if(compara_nomes(nomes[i],nomes[j])){
                    cont++;
                }
            }
        }
        if(cont > max){
            max = cont;
            max_i = i;
        }
    }
    printf("O nome %s foi o que ocorreu mais vezes, totalizando %d ocorrências.\n",nomes[max_i],max);
}



int main(void){
    char nomes[MAX_L][MAX_C];
    int l;
    printf("Digite o número de nomes: ");
    scanf("%d%*c",&l);
    le_matriz(nomes, l,MAX_C-1);
    verifica_nomes(nomes,l);
    return 0;
}
