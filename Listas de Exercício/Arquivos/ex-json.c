#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa_t{
    char nome[30];
    char sobrenome[30];
    int vivo;
    int idade;
    char endereco[50];
}pessoa_t;


void imprime_pessoa(const pessoa_t* pessoa){
    printf("Nome = %s\n",pessoa->nome);
    printf("Sobrenome = %s\n",pessoa->sobrenome);
    printf("Vivo = %d\n",pessoa->vivo);
    printf("Idade = %d\n",pessoa->idade);
    printf("Endereço = %s\n",pessoa->endereco);
}

void filtrar(char* str){
    int l,r;
    int i;
    //Verifica se a string tem aspas
    int aspas = 0;
    for(i=0;str[i]!='\0';i++){
        if(str[i]=='\"'){
            aspas = 1;
            break;
        }
    }
    if(aspas){
        // Encontra a posicao das aspas
        for(l=0;str[l]!='\"';l++);
        l++;
        // Encontra a posicao das aspas
        for(r=l;str[r]!='\"';r++);
        //substitui a segunda aspas por \0
        str[r] = '\0';
        //Copia a string delimitada pelas aspas para o inicio da string
        for(i=0;i<r-l+2;i++){
            str[i] = str[l+i];
        }
    }
    else{
        // Encontra a primeira posicao que nao seja espacos
        for(l=0;str[l]!=' ';l++);
        l++;
        // Encontra a primeira posicao diferente de espaco ou fim de string
        for(r=l;str[r]!= '\0' && str[r]!=' ';r++);
        str[r] = '\0';
        // Copia a substring para o inicio da string
        for(i=0;i<r-l+2;i++){
            str[i] = str[l+i];
        }
    }
}
void atribui_campo(char* linha, pessoa_t* pessoa){
    char chave[200];
    char valor[200];
    char* token = strtok(linha,":");
    strcpy(chave,token);
    token = strtok(NULL,",\n");
    strcpy(valor,token);
    filtrar(chave);
    filtrar(valor);
    if(strcmp(chave,"nome")==0){
        strcpy(pessoa->nome,valor);
    }
    else if(strcmp(chave,"sobrenome")==0){
        strcpy(pessoa->sobrenome,valor);
    }
    else if(strcmp(chave,"vivo") == 0){
        pessoa->vivo = atoi(valor);
    }
    else if(strcmp(chave,"idade") == 0){
        pessoa->idade = atoi(valor);
    }
    else if(strcmp(chave,"endereco") == 0){
        strcpy(pessoa->endereco,valor);
    }
    else{
        printf("%s : %s nao valido.\n",chave,valor);
    }
}

void ler_pessoa(FILE* arq,pessoa_t* pessoa){
    char linha[200];
    // Descarta a primeira linha contendo a chave
    fgets(linha,200,arq);
    int i;
    for(i=0;i<5;i++){
        fgets(linha,200,arq);
        atribui_campo(linha,pessoa);
    }
    //descarta a ultima linha
    fgets(linha,200,arq);
}

int main(int argc, char *argv[]) {
    FILE* arq;
    if(argc!=2){
        printf("Uso: ./<nome do executavel> <arquivo JSON>");
        return 0;
    }
    arq = fopen(argv[1],"r");
    if(arq==NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }
    pessoa_t pessoa;
    ler_pessoa(arq,&pessoa);
    imprime_pessoa(&pessoa);
    return 0;
}
