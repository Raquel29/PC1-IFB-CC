#include <stdio.h>
#include <math.h>

#define MAX 10000


int main(void){
    int nro_primos = 0;
    int primos[MAX];
    int n;
    printf("Digite a quantidade de primos a ser calculada: ");
    scanf("%d",&n);

    primos[0] = 2;
    nro_primos++;

    for(int i=3;nro_primos<n;i+=2){
        int primo = 1;
        int j;
        for(j=0; j<nro_primos && primos[j]<sqrt(i);j++){
            if(i%primos[j] == 0){
                primo = 0;
            }
        }
        if(primo){
            primos[nro_primos++] = i;
        }
    }
    for(int i=0;i<n;i++){
        printf("primos[%d] = %d\n",i,primos[i]);
    }
    return 0;
}
