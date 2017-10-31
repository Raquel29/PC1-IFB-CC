#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[30];
    char emprego[150];
    int idade;
} pessoa;

void le_pessoa(pessoa* p);
void escreve_pessoa_arq_txt(FILE* arq, pessoa* p);
void escreve_pessoa_arq_bin(FILE* arq, pessoa* p);

int main(void){
    FILE* arq_bin, *arq_txt;
    arq_bin = fopen("/home/danielsaad/Desktop/arq.bin","wb");
    arq_txt = fopen("/home/danielsaad/Desktop/arq.txt","w");
    if(arq_bin == NULL || arq_txt == NULL){
        printf("Erro ao abrir arquivos.\n");
        exit(EXIT_FAILURE);
    }

    int n,i;
    printf("Digite a quantidade de pessoas: ");
    scanf("%d%*c",&n);
    for(i=0;i<n;i++){
        pessoa p;
        le_pessoa(&p);
        escreve_pessoa_arq_bin(arq_bin,&p);
        escreve_pessoa_arq_txt(arq_txt,&p);
    }
    return 0;
}

void le_pessoa(pessoa* p){
    printf("Digite o nome: ");
    scanf("%29[^\n]%*c",p->nome);
    printf("Digite o emprego: ");
    scanf("%149[^\n]%*c",p->emprego);
    printf("Digite a idade: ");
    scanf("%d%*c",&(p->idade));
}

void escreve_pessoa_arq_txt(FILE* arq,pessoa* p){
    fprintf(arq, "%s\n",p->nome );
    fprintf(arq, "%s\n",p->emprego );
    fprintf(arq, "%d\n",p->idade );
}

void escreve_pessoa_arq_bin(FILE* arq,pessoa* p){
    fwrite(p, sizeof(pessoa), 1, arq);
}
