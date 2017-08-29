#include <stdio.h>

int main(void){
    int n;
    printf("Digite o número n: ");
    scanf("%d",&n);
    int primo = 1;

    if(n<=0){
        printf("O número lido não é natural, e portanto não pode ser primo e nem composto.\n");
        return 0;
    }

    if(n==1){
        printf("1 não é primo nem composto.\n");
        return 0;
    }

    for(int i=2;i<n;i++){
        if(n % i == 0){
            primo = 0;
        }
    }

    if(primo){
        printf("O número %d é primo.\n",n);
    }
    else{
        printf("O número %d é composto.\n",n);
    }
    return 0;
}
