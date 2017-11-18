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

void le_nome(char padrao[MAX_C],int n){
    printf("Digite o nome a ser procurado na lista: ");
    fgets(padrao,n,stdin);
    if(padrao[strlen(padrao)-1]=='\n') {
            padrao[strlen(padrao)-1] = '\0';
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

void verifica_nomes(char nomes[MAX_L][MAX_C],int l,char* padrao){
    int i;
    int res = 0;
    printf("Verificando se %s ocorre na lista de nomes\n",padrao);
    for(i=0;i<l;i++){
        if(compara_nomes(nomes[i],padrao)){
            res = 1;
            break;
        }
    }
    if(res){
        printf("%s ocorre na lista de nomes.\n",padrao);
    }
    else{
        printf("%s não ocorre na lista de nomes.\n",padrao);
    }
}



int main(void){
    char nomes[MAX_L][MAX_C];
    char padrao[MAX_C];
    int l;
    printf("Digite o número de nomes: ");
    scanf("%d%*c",&l);
    le_matriz(nomes, l,MAX_C-1);
    le_nome(padrao,MAX_C-1);
    verifica_nomes(nomes,l,padrao);
    return 0;
}
