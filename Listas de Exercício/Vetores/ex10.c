#include <stdio.h>

#define MAX 11
int main(void){
    int n,m,i;
    double coef[MAX];
    printf("Digite o grau do polinomio: ");
    scanf("%d",&n);
    for(i=n;i>=0;i--){
        printf("Digite o valor do coeficiente do termo de grau %d: ",i);
        scanf("%lf",&coef[i]);
    }
    printf("Digite a quantidade de consultas: ");
    scanf("%d",&m);
    for(i=0;i<m;i++){
        printf("Digite o valor de x: ");
        double x;
        scanf("%lf",&x);
        double soma = 0;
        double potencia = 1;
        int j;
        for(j=0;j<=n;j++){
            soma+= coef[j]*potencia;
            potencia *= x;
        }
        printf("Valor de P(%lf) = %lf\n",x,soma);
    }
    return 0;
}
