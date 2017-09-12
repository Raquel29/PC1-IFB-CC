#include <stdio.h>
#include <math.h>
#define MAX 10

double potencia(double n,int pot){
    double resultado = 1;
    int i;
    for(i=0;i<pot;i++){
        resultado *= n;
    }
    return resultado;
}
double fatorial(int n){
    double fat = 1.0;
    int i;
    for(i=1;i<=n;i++){
        fat *=i;
    }
    return fat;
}

double my_sin(double x){
    int i;
    double soma = 0;
    for(i=0;i<MAX;i++){
        soma += potencia(-1,i)*(potencia(x,2*i+1)/fatorial(2*i+1));
    }
    return soma;
}

int main(void){
    double x;
    printf("Digite o valor de x em radianos: ");
    scanf("%lf",&x);
    printf("Sin(x) = %.2lf\n",my_sin(x));
    return 0;
}
