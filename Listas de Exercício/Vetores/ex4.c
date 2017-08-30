#include <stdio.h>

#define MAX 100
int main(void){
    int n;
    int i;
    int a[MAX], b[MAX];
    double prod_escalar = 0.0;
    printf("Digite o tamanho dos dois vetores: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Digite o valor de a[%d]: ",i);
        scanf("%d",&a[i]);
        printf("Digite o valor de b[%d]: ",i);
        scanf("%d",&b[i]);
    }

    for(i=0;i<n;i++){
        prod_escalar += a[i]*b[i];
    }
    printf("O produto escalar é: %lf\n",prod_escalar);
    return 0;
}
