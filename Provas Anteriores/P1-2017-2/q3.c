#include <stdio.h>

int main(void){
    int n;
    double x;
    scanf("%d%lf",&n,&x);
    int i;
    double pot = 1;
    double soma = 0;
    for(i=2;i<=n;i++){
        soma+= (pot* (i-1)*i)/2.0;
        pot*=x;
    }
    printf("A soma eh: %lf.\n",soma);
    return 0;
}