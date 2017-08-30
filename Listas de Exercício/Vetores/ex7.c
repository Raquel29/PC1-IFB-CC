#include <stdio.h>

#define MAX 101

int main(void){
    int i;
    int n;
    int fib[MAX];

    fib[0] = 1;
    fib[1] = 1;
    for(i=2;i<MAX;i++){
        fib[i] = fib[i-1]+fib[i-2];
    }

    printf("Entre o número de intervalos a serem consultados: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int a,b;
        printf("Entre o limite inferior do %d intervalo: ",i+1);
        scanf("%d",&a);
        printf("Entre o limite superior do %d intervalo: ",i+1);
        scanf("%d",&b);
        int soma = 0;
        int j;
        for(j=a;j<=b;j++){
            soma+=fib[j];
        }
        printf("O resultado da %d consulta é: %d\n",i+1,soma);
    }

    return 0;
}
