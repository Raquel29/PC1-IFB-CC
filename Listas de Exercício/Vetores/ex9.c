#include <stdio.h>
#define MAX 1000

int main(void){
    double x[MAX];
    int n;
    int i,j;
    printf("Entre a quantidade de números a serem lidos: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Entre o %d número: ",i+1);
        scanf("%lf",&x[i]);
    }
    for(i=0;i<n;i++){
        int qtd = 1;
        int j;
        int pular = 0;
        for(j=i-1;j>=0;j--){
            if(x[i]==x[j]){
                pular = 1;
            }
        }
        if(pular){
            continue;
        }
        for(j=i+1;j<n;j++){
            if(x[i]==x[j]){
                qtd++;
            }
        }
        if(qtd>1){
            printf("%lf ocorre %d vezes.\n",x[i],qtd);
        }
    }
    return 0;
}
