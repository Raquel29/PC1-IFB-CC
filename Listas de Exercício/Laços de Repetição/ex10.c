#include <stdio.h>

int main(void){
    int n;
    double a,r;
    int i;

    printf("Digite o investimento inicial: ");
    scanf("%lf",&a);
    printf("Digite o número de meses: ");
    scanf("%d",&n);
    printf("Digite a taxa de juros ao mes: ");
    scanf("%lf",&r);

    printf("Número de meses              Investimento Acumulado\n ");
    for(i=1;i<=n;i++){
        a *= (1+r);
        printf("%d",i);
        printf("%lf\n",a);
    }
    return 0;
}
