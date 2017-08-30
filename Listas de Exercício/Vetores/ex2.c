#include <stdio.h>
#include <math.h>
#define MAX 10000
int main(void){
    int n;
    int marcado[MAX];
    printf("Digite o limite do crivo: ");
    scanf("%d",&n);
    int i;
    for(int i=0;i<=n;i++){
        marcado[i] = 0;
    }
    marcado[0]=1;
    marcado[1]=1;

    for(i=2;i<=n;i++){
        int j;
        if(!marcado[i]){
            for(j=2;i*j<=n;j++){
                marcado[i*j]= 1;
            }
        }
    }
    printf("Imprimindo lista de primos.\n");
    for(int i=2;i<=n;i++){
        if(!marcado[i]){
            printf("%d\n",i);
        }
    }

    return 0;
}
