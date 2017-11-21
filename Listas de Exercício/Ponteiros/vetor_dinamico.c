#include <stdio.h>
#include <stdlib.h>
typedef struct vetor_t{
    int* v;
    int n_elementos;
    int capacidade;
}vetor_t;

void inicializa_vetor(vetor_t* vet){
    vet->v = calloc(4,sizeof(int));
    vet->n_elementos = 0;
    vet->capacidade = 4;
}

void insere_final(vetor_t* vet,int elem){
    if(vet->n_elementos == vet->capacidade){
        vet->v = realloc(vet->v,sizeof(int)*vet->capacidade* 2);
        vet->capacidade = vet->capacidade*2;
    }
    vet->v[vet->n_elementos] = elem;
    vet->n_elementos++;
}

void remove_final(vetor_t* vet){
    vet->n_elementos--;
    if(vet->capacidade!=4 && vet->n_elementos <= vet->capacidade/4){
        vet->v = realloc(vet->v,sizeof(int)*vet->capacidade/2);
        vet->capacidade = vet->capacidade/2;
    }
}

void imprime_vetor(vetor_t vet){
    int i;
    for(i=0;i<vet.n_elementos;i++){
        printf("v[%d] = %d\n",i,vet.v[i]);
    }
}

int main(void){
    vetor_t vet;
    inicializa_vetor(&vet);
    insere_final(&vet, 0);
    insere_final(&vet, 1);
    insere_final(&vet, 2);
    insere_final(&vet, 3);
    insere_final(&vet, 4);
    insere_final(&vet, 5);
    insere_final(&vet, 6);
    remove_final(&vet);
    remove_final(&vet);
    remove_final(&vet);
    remove_final(&vet);
    remove_final(&vet);
    imprime_vetor(vet);
}
