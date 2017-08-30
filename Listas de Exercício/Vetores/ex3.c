#include <stdio.h>
#include <math.h>

#define MAX 10

int main(void){
    int n;
    int i;
    double x[MAX];
    double soma = 0.0;
    double media;
    double desvio_padrao = 0;
    printf("Digite o numero de valores a serem lidos: ");
    scanf("%d",&n);


    for(i=0;i<n;i++){
        printf("Digite o valor de x[%d]: ",i);
        scanf("%lf",&x[i]);
        soma +=x[i];
    }

    media = soma/n;

    for(i=0;i<n;i++){
        desvio_padrao += pow((x[i]-media),2);
    }
    desvio_padrao/= n;
    desvio_padrao = sqrt(desvio_padrao);

    printf("O desvio padrao é: %lf\n",desvio_padrao);
    return 0;
}
