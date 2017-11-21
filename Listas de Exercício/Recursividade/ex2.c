#include <stdio.h>
#include <stdlib.h>

void imprime_rec(int* v,int i,int n){
    if(i==n){
        return;
    }
    imprime_rec(v, i+1, n);
    printf("v[%d] = %d\n",i,v[i]);
}

int main(void){
    int n, *v;
    int i;
    printf("Digite o nro de elementos do vetor: ");
    scanf("%d",&n);
    v = calloc(n,sizeof(int));
    for(i=0;i<n;i++){
        printf("v[%d] = ",i);
        scanf("%d",&v[i]);
    }
    imprime_rec(v,0,n);
}
