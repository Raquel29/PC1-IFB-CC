#include <stdio.h>

int main(void){
    int n;
    printf("Digite um inteiro n: ");
    scanf("%d",&n);

    int i;
    for(i=1;i<=n;i++){
        int j;
        for(j=1;j<=n;j++){
            printf("(%d,%d)",i,j);
            if(j==n){
                printf("\n");
            }
            else{
                printf(",");
            }
        }
    }
    return 0;
}
