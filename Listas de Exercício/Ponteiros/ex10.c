#include <stdio.h>
#include <stdlib.h>

void push_back(int* v,int* n,int* capacidade, int valor){
    if(*n == *capacidade){
        v = realloc(v,*capacidade * 2 * sizeof(int));
        *capacidade = *capacidade * 2;
    }
    v[(*n)++] = valor;
}

void pop_back(int* v,int* n,int* capacidade){
    (*n)--;
    if(*n < *capacidade/4){
        v = realloc(v,*capacidade/2 * sizeof(int));
        *capacidade = *capacidade/2;
    }
}

void print(int * v,int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}



int main(void){
    int * v = calloc(4,sizeof(int));
    int capacidade = 4;
    int n = 0;

    int i;
    for(i=0;i<100;i++){
        push_back(v,&n,&capacidade,i);
    }
    print(v,n);
    printf("n = %d\ncapacidade = %d\n",n,capacidade);
    for(i=0;i<90;i++){
        pop_back(v,&n,&capacidade);
    }
    print(v,n);
    printf("n = %d\ncapacidade = %d\n",n,capacidade);


    free(v);

    return 0;
}
