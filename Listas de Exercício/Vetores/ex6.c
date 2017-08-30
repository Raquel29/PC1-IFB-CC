#include <stdio.h>

#define MAX 1000

int main(void){
    int vetor_int[MAX];
    int n;
    int i;
    printf("Digite a quantidade de inteiros a serem lidos: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Digite o %d inteiro: ",i+1);
        scanf("%d",&vetor_int[i]);
    }
    for(i=0;i<n/2;i++){
        int tmp = vetor_int[i];
        vetor_int[i] = vetor_int[n-i-1];
        vetor_int[n-i-1] = tmp;
    }
    printf("Vetor invertido\n");
    for(i=0;i<n;i++){
        printf("vetor_int[%d] = %d\n",i,vetor_int[i]);
    }
    return 0;
}
