#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[30];
    char emprego[150];
    int idade;
} pessoa;

void imprime_pessoa(pessoa* p){
    printf("Nome: %s\n",p->nome);
    printf("Emprego: %s\n",p->emprego);
    printf("Idade: %d\n",p->idade);
}

int main(void){
    FILE* arq = fopen("/home/danielsaad/Desktop/arq.bin","rb");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }
    pessoa p;
    fseek(arq,sizeof(pessoa), SEEK_SET);
    fread(&p,sizeof(pessoa),1,arq);
    imprime_pessoa(&p);
    return 0;
}
