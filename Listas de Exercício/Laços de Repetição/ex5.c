#include <stdio.h>

int main(void){
    for(int i=0;i<5;i++){
        int num_estrela = 2*i+1;
        int num_espaco = 9-num_estrela;
        int j;
        for(j=0;j<num_espaco/2;j++){
            printf(" ");
        }
        for(j=0;j<num_estrela;j++){
            printf("*");
        }
        for(j=0;j<num_espaco/2;j++){
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}
