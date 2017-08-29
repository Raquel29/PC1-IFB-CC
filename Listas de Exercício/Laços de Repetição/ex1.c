#include <stdio.h>

#define MAX 1001

int main(void){
    int n;
    printf("Digite o valor de n: ");
    scanf("%d",&n);
    int i;
    int menor, maior,seg_menor, seg_maior;
    for(i=0;i<n;i++){
        int num;
        printf("Digite o %d inteiro: ",i+1);
        scanf("%d",&num);
        if(i==0){
            menor = num;
            maior = num;
        }
        else if(i==1){
            if(num >= maior){
                seg_maior = maior;
                maior = num;
            }
            else{
                seg_maior = num;
            }
            if(num<= menor){
                seg_menor =  menor;
                menor = num;
            }
            else{
                seg_menor = num;
            }
        }
        else{
            if(num>=maior){
                seg_maior = maior;
                maior = num;
            }
            else if(num<= menor){
                seg_menor = menor;
                menor = num;
            }
        }
    }
    if(n==0){
        printf("Não foram lidos números.\n");
    }
    else if(n==1){
        printf("Maior elemento = %d\n",maior);
        printf("Menor elemento = %d\n",menor);
    }
    else{
        printf("Maior elemento = %d\n",maior);
        printf("Segundo maior elemento = %d\n",seg_maior);
        printf("Menor elemento = %d\n",menor);
        printf("Segundo menor elemento = %d\n",seg_menor);

    }
    return 0;
}
